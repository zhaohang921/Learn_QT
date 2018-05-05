/********************************************************************************
** Form generated from reading UI file 'first_step_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_STEP_DIALOG_H
#define UI_FIRST_STEP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_firstStepDialog
{
public:

    void setupUi(QDialog *firstStepDialog)
    {
        if (firstStepDialog->objectName().isEmpty())
            firstStepDialog->setObjectName(QStringLiteral("firstStepDialog"));
        firstStepDialog->resize(400, 300);

        retranslateUi(firstStepDialog);

        QMetaObject::connectSlotsByName(firstStepDialog);
    } // setupUi

    void retranslateUi(QDialog *firstStepDialog)
    {
        firstStepDialog->setWindowTitle(QApplication::translate("firstStepDialog", "\347\254\254\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class firstStepDialog: public Ui_firstStepDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_STEP_DIALOG_H
