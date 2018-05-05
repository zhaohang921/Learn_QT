/********************************************************************************
** Form generated from reading UI file 'secure_tip_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECURE_TIP_DIALOG_H
#define UI_SECURE_TIP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_secureTipDialog
{
public:
    QLabel *label;
    QPushButton *ok_pushButton;

    void setupUi(QDialog *secureTipDialog)
    {
        if (secureTipDialog->objectName().isEmpty())
            secureTipDialog->setObjectName(QStringLiteral("secureTipDialog"));
        secureTipDialog->resize(400, 300);
        label = new QLabel(secureTipDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 120, 60, 16));
        ok_pushButton = new QPushButton(secureTipDialog);
        ok_pushButton->setObjectName(QStringLiteral("ok_pushButton"));
        ok_pushButton->setGeometry(QRect(270, 250, 113, 32));

        retranslateUi(secureTipDialog);

        QMetaObject::connectSlotsByName(secureTipDialog);
    } // setupUi

    void retranslateUi(QDialog *secureTipDialog)
    {
        secureTipDialog->setWindowTitle(QApplication::translate("secureTipDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("secureTipDialog", "\346\263\250\346\204\217\345\256\211\345\205\250\357\274\201", nullptr));
        ok_pushButton->setText(QApplication::translate("secureTipDialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secureTipDialog: public Ui_secureTipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECURE_TIP_DIALOG_H
