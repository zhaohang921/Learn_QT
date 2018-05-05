/********************************************************************************
** Form generated from reading UI file 'sixth_step_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIXTH_STEP_DIALOG_H
#define UI_SIXTH_STEP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_sixth_step_Dialog
{
public:

    void setupUi(QDialog *sixth_step_Dialog)
    {
        if (sixth_step_Dialog->objectName().isEmpty())
            sixth_step_Dialog->setObjectName(QStringLiteral("sixth_step_Dialog"));
        sixth_step_Dialog->resize(400, 300);

        retranslateUi(sixth_step_Dialog);

        QMetaObject::connectSlotsByName(sixth_step_Dialog);
    } // setupUi

    void retranslateUi(QDialog *sixth_step_Dialog)
    {
        sixth_step_Dialog->setWindowTitle(QApplication::translate("sixth_step_Dialog", "\347\254\254\345\205\255\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sixth_step_Dialog: public Ui_sixth_step_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIXTH_STEP_DIALOG_H
