/********************************************************************************
** Form generated from reading UI file 'choose_mode_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_MODE_DIALOG_H
#define UI_CHOOSE_MODE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_chooseModeDialog
{
public:
    QPushButton *watchVideo_pushButton;
    QPushButton *startTrain_pushButton;

    void setupUi(QDialog *chooseModeDialog)
    {
        if (chooseModeDialog->objectName().isEmpty())
            chooseModeDialog->setObjectName(QStringLiteral("chooseModeDialog"));
        chooseModeDialog->resize(400, 300);
        watchVideo_pushButton = new QPushButton(chooseModeDialog);
        watchVideo_pushButton->setObjectName(QStringLiteral("watchVideo_pushButton"));
        watchVideo_pushButton->setGeometry(QRect(140, 100, 113, 32));
        startTrain_pushButton = new QPushButton(chooseModeDialog);
        startTrain_pushButton->setObjectName(QStringLiteral("startTrain_pushButton"));
        startTrain_pushButton->setGeometry(QRect(140, 150, 113, 32));

        retranslateUi(chooseModeDialog);

        QMetaObject::connectSlotsByName(chooseModeDialog);
    } // setupUi

    void retranslateUi(QDialog *chooseModeDialog)
    {
        chooseModeDialog->setWindowTitle(QApplication::translate("chooseModeDialog", "\351\200\211\346\213\251\345\237\271\350\256\255\346\226\271\345\274\217", nullptr));
        watchVideo_pushButton->setText(QApplication::translate("chooseModeDialog", "\350\247\202\347\234\213\345\256\236\351\231\205\346\274\224\347\244\272", nullptr));
        startTrain_pushButton->setText(QApplication::translate("chooseModeDialog", "\347\233\264\346\216\245\350\277\233\345\205\245\345\237\271\350\256\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chooseModeDialog: public Ui_chooseModeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_MODE_DIALOG_H
