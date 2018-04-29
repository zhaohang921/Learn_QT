#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    //trimmed() ：去除字符串前后的空白字符
    if (ui->usrLineEdit->text().trimmed() == tr("zhaohang") &&
            ui->pwdLineEdit->text().trimmed() == tr("123456")){
        accept();
    } else {
        QMessageBox::warning(this,tr("警告！"),
                             tr("用户名和密码错误！"),
                             QMessageBox::Yes);
        // 清空内容并定位光标
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }
}

