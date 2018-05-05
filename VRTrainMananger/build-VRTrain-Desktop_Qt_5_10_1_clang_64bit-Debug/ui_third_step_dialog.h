/********************************************************************************
** Form generated from reading UI file 'third_step_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRD_STEP_DIALOG_H
#define UI_THIRD_STEP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_third_step_Dialog
{
public:

    void setupUi(QDialog *third_step_Dialog)
    {
        if (third_step_Dialog->objectName().isEmpty())
            third_step_Dialog->setObjectName(QStringLiteral("third_step_Dialog"));
        third_step_Dialog->resize(400, 300);

        retranslateUi(third_step_Dialog);

        QMetaObject::connectSlotsByName(third_step_Dialog);
    } // setupUi

    void retranslateUi(QDialog *third_step_Dialog)
    {
        third_step_Dialog->setWindowTitle(QApplication::translate("third_step_Dialog", "\347\254\254\344\270\211\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class third_step_Dialog: public Ui_third_step_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRD_STEP_DIALOG_H
