/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QLabel *serverStatusLabel;
    QProgressBar *progressBar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *serverOpenbtn;
    QPushButton *serverSendBtn;
    QPushButton *serverCloseBtn;

    void setupUi(QDialog *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QStringLiteral("TcpServer"));
        TcpServer->resize(400, 300);
        serverStatusLabel = new QLabel(TcpServer);
        serverStatusLabel->setObjectName(QStringLiteral("serverStatusLabel"));
        serverStatusLabel->setGeometry(QRect(130, 90, 121, 16));
        QFont font;
        font.setFamily(QStringLiteral("Heiti SC"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        serverStatusLabel->setFont(font);
        serverStatusLabel->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(TcpServer);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(100, 130, 211, 21));
        progressBar->setValue(0);
        widget = new QWidget(TcpServer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 190, 343, 32));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        serverOpenbtn = new QPushButton(widget);
        serverOpenbtn->setObjectName(QStringLiteral("serverOpenbtn"));

        horizontalLayout->addWidget(serverOpenbtn);

        serverSendBtn = new QPushButton(widget);
        serverSendBtn->setObjectName(QStringLiteral("serverSendBtn"));

        horizontalLayout->addWidget(serverSendBtn);

        serverCloseBtn = new QPushButton(widget);
        serverCloseBtn->setObjectName(QStringLiteral("serverCloseBtn"));

        horizontalLayout->addWidget(serverCloseBtn);


        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QDialog *TcpServer)
    {
        TcpServer->setWindowTitle(QApplication::translate("TcpServer", "\345\217\221\351\200\201\347\253\257", nullptr));
        serverStatusLabel->setText(QApplication::translate("TcpServer", "\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266\357\274\201", nullptr));
        serverOpenbtn->setText(QApplication::translate("TcpServer", "\346\211\223\345\274\200", nullptr));
        serverSendBtn->setText(QApplication::translate("TcpServer", "\345\217\221\351\200\201", nullptr));
        serverCloseBtn->setText(QApplication::translate("TcpServer", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
