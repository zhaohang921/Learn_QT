#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isUntitled = true;
    curFile = tr("未命名.txt");
    setWindowTitle(curFile); //初始化窗口标题为未命名

    //创建了一个对话框，然后将一个行编辑器和一个按钮放到了上面，并使用布局管理器进行布局。
    //最后将按钮的单击信号关联到了自定义的显示查找结果槽上。
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    findLineEdit = new QLineEdit(findDlg);
    QPushButton *btn = new QPushButton(tr("查找下一个"), findDlg);
    QVBoxLayout *layout = new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &MainWindow::showFindText);

//    ui->statusBar->showMessage(tr("欢迎访问Qt开源社区！"), 2000);//设置显示时长,2s

    //在状态栏添加一个标签部件用来显示一般的提示信息
    statusLabel = new QLabel;
    statusLabel->setMinimumSize(150,20);
    statusLabel->setFrameShape(QFrame::WinPanel);
    statusLabel->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(statusLabel);
    statusLabel->setText(tr("欢迎访问Qt开源社区！"));

    //显示永久信息，它会生成在状态栏的最右端，不会被临时消息所掩盖
    QLabel *permanent = new QLabel;
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText(tr("<a href=\"http://www.baidu.com\">www.baidu.com</a>"));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    //这里先使用maybeSave()来判断文档是否需要保存，如果已经保存完了，则新建文档，并进行初始化。
    if (maybeSave()){
        isUntitled = true;
        curFile = tr("未命名.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maybeSave() //判断是否需要保存
{
    //这里先使用了isModified()来判断文档是否被更改了，如果被更改了，则弹出对话框让用户选择是否进行保存，或者取消操作。
    if (ui->textEdit->document()->isModified()){
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr(" 尚未保存，是否保存？"));
        QPushButton *yesBtn = box.addButton(tr("是(&Y)"), QMessageBox::YesRole);
        QPushButton *noBtn = box.addButton(tr("否(&N)"), QMessageBox::NoRole);
        QPushButton *cancelBtn = box.addButton(tr("取消"), QMessageBox::RejectRole);
        box.exec();
        if (box.clickedButton() == yesBtn){
            return save();
        } else if (box.clickedButton() == cancelBtn){
            return false;
        }
    }
    return true;
}

bool MainWindow::save()
{
    //如果文档以前没有保存过，那么执行另存为操作saveAs()，如果已经保存过，那么调用saveFile()执行文件保存操作。
    if (isUntitled){
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    //这里使用QFileDialog来实现了一个另存为对话框，并且获取了文件的路径，然后使用文件路径来保存文件。
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), curFile);
    if (fileName.isEmpty()){
        return false;
    }
    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString& fileName)
{
    //先是使用一个QFile类对象来指向要保存的文件，然后使用文本写入方式将其打开。
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法写入文件 %1: /n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    //打开后再使用QTextStream文本流将编辑器中的内容写入到文件中。
    QTextStream out(&file);
    //鼠标指针变为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    QApplication::restoreOverrideCursor();
    isUntitled = false;
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

bool MainWindow::loadFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法写入文件 %1: /n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    //鼠标指针变为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlaceholderText(in.readAll());
    QApplication::restoreOverrideCursor();
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_action_New_triggered()
{
    newFile();
}

void MainWindow::on_action_Open_triggered()
{
    if (maybeSave()){
        QString fileName = QFileDialog::getOpenFileName(this);
        //如果文件名不为空，则加载文件
        if (!fileName.isEmpty()){
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }
    }
}

void MainWindow::on_action_Save_triggered()
{
    save();
}

void MainWindow::on_action_SaveAs_triggered()
{
    saveAs();
}

void MainWindow::on_action_Close_triggered()
{
    if (maybeSave()){
        ui->textEdit->setVisible(false);
    }
}

void MainWindow::on_action_Exit_triggered()
{
    //先执行关闭操作，再退出程序
    on_action_Close_triggered();
    //qApp是指向应用程序的全局指针
    qApp->quit();
}

void MainWindow::on_action_Undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_Cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_action_Copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_Paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::showFindText()
{
    //获取行编辑器中要查找的字符串
    QString str = findLineEdit->text();
    if (!ui->textEdit->find(str, QTextDocument::FindBackward)){
        QMessageBox::warning(this, tr("查找"),
                             tr("找不到%1").arg(str));
//        这里的%1作为占位符，在显示时会被arg()中的参数替换掉，这是一种常用的在字符串中添加变量值的方式。
    }

}

void MainWindow::closeEvent(QCloseEvent *event) //关闭事件
{
    if (maybeSave()){
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::on_action_Find_triggered()
{
    findDlg->show();
}
