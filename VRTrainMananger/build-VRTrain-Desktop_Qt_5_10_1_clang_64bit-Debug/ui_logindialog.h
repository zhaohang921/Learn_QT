/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginDialog
{
public:
    QPushButton *login_pushButton;
    QPushButton *logout_pushButton;
    QLabel *username_label;
    QLabel *password_label;
    QLineEdit *username_lineEdit;
    QLineEdit *password_lineEdit;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QStringLiteral("loginDialog"));
        loginDialog->resize(400, 300);
        login_pushButton = new QPushButton(loginDialog);
        login_pushButton->setObjectName(QStringLiteral("login_pushButton"));
        login_pushButton->setGeometry(QRect(90, 180, 101, 32));
        logout_pushButton = new QPushButton(loginDialog);
        logout_pushButton->setObjectName(QStringLiteral("logout_pushButton"));
        logout_pushButton->setGeometry(QRect(200, 180, 101, 32));
        username_label = new QLabel(loginDialog);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(90, 80, 60, 16));
        password_label = new QLabel(loginDialog);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setGeometry(QRect(90, 120, 60, 16));
        username_lineEdit = new QLineEdit(loginDialog);
        username_lineEdit->setObjectName(QStringLiteral("username_lineEdit"));
        username_lineEdit->setGeometry(QRect(150, 80, 151, 21));
        password_lineEdit = new QLineEdit(loginDialog);
        password_lineEdit->setObjectName(QStringLiteral("password_lineEdit"));
        password_lineEdit->setGeometry(QRect(150, 120, 151, 21));
        password_lineEdit->setEchoMode(QLineEdit::Password);

        retranslateUi(loginDialog);
        QObject::connect(logout_pushButton, SIGNAL(clicked()), loginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", nullptr));
        login_pushButton->setText(QApplication::translate("loginDialog", "\347\231\273\351\231\206", nullptr));
        logout_pushButton->setText(QApplication::translate("loginDialog", "\351\200\200\345\207\272", nullptr));
        username_label->setText(QApplication::translate("loginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        password_label->setText(QApplication::translate("loginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        username_lineEdit->setPlaceholderText(QApplication::translate("loginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        password_lineEdit->setPlaceholderText(QApplication::translate("loginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
