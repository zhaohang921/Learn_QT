/********************************************************************************
** Form generated from reading UI file 'fourth_step_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURTH_STEP_DIALOG_H
#define UI_FOURTH_STEP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_fourth_step_Dialog
{
public:

    void setupUi(QDialog *fourth_step_Dialog)
    {
        if (fourth_step_Dialog->objectName().isEmpty())
            fourth_step_Dialog->setObjectName(QStringLiteral("fourth_step_Dialog"));
        fourth_step_Dialog->resize(400, 300);

        retranslateUi(fourth_step_Dialog);

        QMetaObject::connectSlotsByName(fourth_step_Dialog);
    } // setupUi

    void retranslateUi(QDialog *fourth_step_Dialog)
    {
        fourth_step_Dialog->setWindowTitle(QApplication::translate("fourth_step_Dialog", "\347\254\254\345\233\233\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fourth_step_Dialog: public Ui_fourth_step_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURTH_STEP_DIALOG_H
