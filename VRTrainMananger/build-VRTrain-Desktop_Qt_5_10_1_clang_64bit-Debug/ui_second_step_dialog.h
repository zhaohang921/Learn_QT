/********************************************************************************
** Form generated from reading UI file 'second_step_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_STEP_DIALOG_H
#define UI_SECOND_STEP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_secondStepDialog
{
public:

    void setupUi(QDialog *secondStepDialog)
    {
        if (secondStepDialog->objectName().isEmpty())
            secondStepDialog->setObjectName(QStringLiteral("secondStepDialog"));
        secondStepDialog->resize(400, 300);

        retranslateUi(secondStepDialog);

        QMetaObject::connectSlotsByName(secondStepDialog);
    } // setupUi

    void retranslateUi(QDialog *secondStepDialog)
    {
        secondStepDialog->setWindowTitle(QApplication::translate("secondStepDialog", "\347\254\254\344\272\214\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondStepDialog: public Ui_secondStepDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_STEP_DIALOG_H
