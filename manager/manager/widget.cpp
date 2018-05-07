#include "widget.h"
#include "ui_widget.h"
#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSplitter>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 固定窗口大小
    setFixedSize(750, 500);
    ui->stackedWidget->setCurrentIndex(0);

    QSqlQueryModel *typeModel = new QSqlQueryModel(this);
    typeModel->setQuery("select name from type");
    ui->sellTypeComboBox->setModel(typeModel);
    QSplitter *splitter = new QSplitter(ui->managePage);
    splitter->resize(700, 360);
    splitter->move(0, 50);
    splitter->addWidget(ui->toolBox);
    splitter->addWidget(ui->dailyList);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 1);

    on_sellCancelBtn_clicked();

    showDailyList();
}

Widget::~Widget()
{
    delete ui;
}

// 获取时间和日期
QString Widget::getDateTime(Widget::DateTimeType type)
{
    QDateTime datetime = QDateTime::currentDateTime();
    QString date = datetime.toString("yyyy-MM-dd");
    QString time = datetime.toString("hh:mm");
    QString dateAndTime = datetime.toString("yyyy-MM-dd dddd hh:mm");
    if (type == Date){
        return date;
    } else if (type == Time){
        return time;
    } else {
        return dateAndTime;
    }
}

void Widget::on_sellTypeComboBox_currentIndexChanged(QString type)
{
    if (type == "请选择类型"){
        on_sellCancelBtn_clicked();
//        qDebug() << "请选择类型";
    } else {
//        qDebug() << type;
        ui->sellBrandComboBox->setEnabled(true);
        QSqlQueryModel *model = new QSqlQueryModel(this);
        model->setQuery(QString("select name from brand where type = '%1'").arg(type));
        ui->sellBrandComboBox->setModel(model);
        ui->sellCancelBtn->setEnabled(true);
    }
}

void Widget::on_sellBrandComboBox_currentTextChanged(QString brand)
{
    // 设置几个部件的状态
    ui->sellNumSpinBox->setValue(0);
    ui->sellNumSpinBox->setEnabled(false);
    ui->sellSumLineEdit->clear();
    ui->sellSumLineEdit->setEnabled(false);
    ui->sellOkBtn->setEnabled(false);

    // 查询当前类型的品牌单价和剩余数量
    QSqlQuery query;
    query.exec(QString("select price from brand where name = '%1' and type = '%2'")
               .arg(brand).arg(ui->sellTypeComboBox->currentText()));
    query.next();
    ui->sellPriceLineEdit->setEnabled(true);
    ui->sellPriceLineEdit->setReadOnly(true);
    ui->sellPriceLineEdit->setText(query.value(0).toString());

    query.exec(QString("select last from brand where name = '%1' and type = '%2'")
               .arg(brand).arg(ui->sellTypeComboBox->currentText()));
    query.next();
    int num = query.value(0).toInt();
    if (num == 0){
        QMessageBox::information(this, tr("提示"), tr("该商品已经售完！"), QMessageBox::Ok);
    } else {
        ui->sellNumSpinBox->setEnabled(true);
        // 将购买数量选择框的上限设置为当前的剩余数量
        ui->sellNumSpinBox->setMaximum(num);
        ui->sellLastNumLabel->setText(tr("剩余数量：%1").arg(num));
        ui->sellLastNumLabel->setVisible(true);
    }
}

void Widget::on_sellNumSpinBox_valueChanged(int value)
{
    // 更改了购买数量后会自动显示总的金额
    if (value == 0){
        ui->sellSumLineEdit->clear();
        ui->sellSumLineEdit->setEnabled(false);
        ui->sellOkBtn->setEnabled(false);
    } else {
        ui->sellSumLineEdit->setEnabled(true);
        ui->sellSumLineEdit->setReadOnly(true);
        qreal sum = value * ui->sellPriceLineEdit->text().toInt();
        ui->sellSumLineEdit->setText(QString::number(sum));
        ui->sellOkBtn->setEnabled(true);
    }
}

void Widget::on_sellCancelBtn_clicked()
{
    ui->sellTypeComboBox->setCurrentIndex(0);
    ui->sellBrandComboBox->clear();
    ui->sellPriceLineEdit->clear();
    ui->sellNumSpinBox->clear();
    ui->sellSumLineEdit->clear();
}

void Widget::on_sellOkBtn_clicked()
{
    QString type = ui->sellTypeComboBox->currentText();
    QString name = ui->sellBrandComboBox->currentText();
    int value = ui->sellNumSpinBox->value();
    // sellNumSpinBox->maximum() 就是以前的剩余量
    int last = ui->sellNumSpinBox->maximum() - value;

    QSqlQuery query;
    // 获取以前的销售量
    query.exec(QString("select sell from brand where name = '%1' and type = '%2'").arg(name).arg(type));
    // 执行完exec()函数后，QSqlQuery的内部指针会位于第一条记录前面的位置，调用next()可以使指针
    query.next();
    // value(0)返回当前记录的第一个字段值
    int sell = query.value(0).toInt() + value;

    // 事务操作
    QSqlDatabase::database().transaction();
    bool rtn = query.exec(QString("update brand set sell = %1, last = %2 where name = '%3' and type = '%4'")
                          .arg(sell).arg(last).arg(name).arg(type));

    if (rtn){
        QSqlDatabase::database().commit();
        QMessageBox::information(this, tr("提示"), tr("购买成功！"), QMessageBox::Ok);
        writeXml();
        showDailyList();
        on_sellCancelBtn_clicked();
    } else {
        QSqlDatabase::database().rollback();
    }

}

//读取XML文档
bool Widget::docRead()
{
    QFile file("data.xml");
    if (!file.open(QIODevice::ReadOnly)){
        return false;
    }
    if (!doc.setContent(&file)){
        file.close();
        return false;
    }
    file.close();
    return true;
}

// 写入xml文档
bool Widget::docWrite()
{
    QFile file("data.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        return false;
    }
    QTextStream out(&file);
    doc.save(out, 4);
    file.close();
    return true;
}

//修改xml文档
void Widget::writeXml()
{
    // 先从文件读取
    if (docRead()){
        QString currentDate = getDateTime(Date);
        QDomElement root = doc.documentElement();
        // 根据是否有日期节点进行处理
        if (!root.hasChildNodes()){
            QDomElement date = doc.createElement(QString("日期"));
            QDomAttr curDate = doc.createAttribute("date");
            curDate.setValue(currentDate);
            date.setAttributeNode(curDate);
            root.appendChild(date);
            createNodes(date);
        } else {
            QDomElement date = root.lastChild().toElement();
            // 根据是否已经有今天的日期节点进行处理
            if (date.attribute("date") == currentDate){
                createNodes(date);
            } else{
                QDomElement date = doc.createElement(QString("日期"));
                QDomAttr curDate = doc.createAttribute("date");
                curDate.setValue(currentDate);
                date.setAttributeNode(curDate);
                root.appendChild(date);
                createNodes(date);
            }
        }
        //写入到文件
        docWrite();
    }
}

//创建销售商品信息的节点
void Widget::createNodes(QDomElement &date)
{
    QDomElement time = doc.createElement(QString("时间"));
    QDomAttr curTime = doc.createAttribute("time");
    curTime.setValue(getDateTime(Time));
    time.setAttributeNode(curTime);
    date.appendChild(time);
    QDomElement type = doc.createElement(QString("类型"));
    QDomElement brand = doc.createElement(QString("品牌"));
    QDomElement price = doc.createElement(QString("单价"));
    QDomElement num = doc.createElement(QString("数量"));
    QDomElement sum = doc.createElement(QString("金额"));
    QDomText text;
    text = doc.createTextNode(QString("%1")
                              .arg(ui->sellTypeComboBox->currentText()));
    type.appendChild(text);
    text = doc.createTextNode(QString("%1")
                              .arg(ui->sellBrandComboBox->currentText()));
    brand.appendChild(text);
    text = doc.createTextNode(QString("%1")
                              .arg(ui->sellPriceLineEdit->text()));
    price.appendChild(text);
    text = doc.createTextNode(QString("%1")
                              .arg(ui->sellNumSpinBox->value()));
    num.appendChild(text);
    text = doc.createTextNode(QString("%1")
                              .arg(ui->sellSumLineEdit->text()));
    sum.appendChild(text);
    time.appendChild(type);
    time.appendChild(brand);
    time.appendChild(price);
    time.appendChild(num);
    time.appendChild(sum);
}

// 显示日销售清单
void Widget::showDailyList()
{
    ui->dailyList->clear();
    if (docRead()){
        QDomElement root = doc.documentElement();
        QString title = root.tagName();
        QListWidgetItem *titleItem = new QListWidgetItem;
        titleItem->setText(QString("-----%1-----").arg(title));
        titleItem->setTextAlignment(Qt::AlignHCenter);
        ui->dailyList->addItem(titleItem);
        if (root.hasChildNodes()){
            QString currentDate = getDateTime(Date);
            QDomElement dateElement = root.lastChild().toElement();
            QString date = dateElement.attribute("date");
            if (date == currentDate){
                ui->dailyList->addItem("");
                ui->dailyList->addItem(QString("日期:%1").arg(date));
                ui->dailyList->addItem("");
                QDomNodeList children = dateElement.childNodes();
                // 遍历当日销售的所有商品
                for (int i = 0; i < children.count(); ++i){
                    QDomNode node = children.at(i);
                    QString time = node.toElement().attribute("time");
                    QDomNodeList list = node.childNodes();
                    QString type = list.at(0).toElement().text();
                    QString brand = list.at(1).toElement().text();
                    QString price = list.at(2).toElement().text();
                    QString num = list.at(3).toElement().text();
                    QString sum = list.at(4).toElement().text();
                    QString str = time + "出售" + brand + type
                            + " " + num + "台, " + "单价：" + price
                            + "元， 共" + sum + "元";
                    QListWidgetItem *tempItem = new QListWidgetItem;
                    tempItem->setText("*************************");
                    tempItem->setTextAlignment(Qt::AlignCenter);
                    ui->dailyList->addItem(tempItem);
                    ui->dailyList->addItem(str);
                }
            }
        }
    }
}
