#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    //其中x()和y()分别用来返回鼠标光标所在位置的x和y坐标值
    //鼠标在界面上点击时，按钮就会显示出当前鼠标的坐标值
    ui->pushButton->setText(tr("(%1, %2)").arg(e->x()).arg(e->y()));
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    int x = ui->pushButton->x();
    int y = ui->pushButton->y();
    //使用key()函数获取按下的按键，如果是指定的W、S、A、D等按键时则移动按钮
    switch (e->key()) {
    case Qt::Key_W :
        ui->pushButton->move(x, y - 10);
        break;
    case Qt::Key_A :
        ui->pushButton->move(x - 10, y);
        break;
    case Qt::Key_S :
        ui->pushButton->move(x, y + 10);
        break;
    case Qt::Key_D :
        ui->pushButton->move(x + 10, y);
        break;
    default:
        break;
    }
}
