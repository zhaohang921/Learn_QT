#include "login_dialog.h"
#include "ui_login_dialog.h"
#include <QMessageBox>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_login_pushButton_clicked()
{
    //trimmed() ：去除字符串前后的空白字符
    if (ui->username_lineEdit->text().trimmed() == tr("zh") &&
            ui->password_lineEdit->text().trimmed() == tr("1")){
        accept();
    } else {
        QMessageBox::warning(this,tr("警告！"),
                             tr("用户名和密码错误！"),
                             QMessageBox::Yes);
        // 清空内容并定位光标
        ui->username_lineEdit->clear();
        ui->password_lineEdit->clear();
        ui->username_lineEdit->setFocus();
    }
}
