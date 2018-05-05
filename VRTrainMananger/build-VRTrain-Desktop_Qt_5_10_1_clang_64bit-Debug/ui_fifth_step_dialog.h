/********************************************************************************
** Form generated from reading UI file 'fifth_step_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIFTH_STEP_DIALOG_H
#define UI_FIFTH_STEP_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_fifth_step_Dialog
{
public:

    void setupUi(QDialog *fifth_step_Dialog)
    {
        if (fifth_step_Dialog->objectName().isEmpty())
            fifth_step_Dialog->setObjectName(QStringLiteral("fifth_step_Dialog"));
        fifth_step_Dialog->resize(400, 300);

        retranslateUi(fifth_step_Dialog);

        QMetaObject::connectSlotsByName(fifth_step_Dialog);
    } // setupUi

    void retranslateUi(QDialog *fifth_step_Dialog)
    {
        fifth_step_Dialog->setWindowTitle(QApplication::translate("fifth_step_Dialog", "\347\254\254\344\272\224\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fifth_step_Dialog: public Ui_fifth_step_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIFTH_STEP_DIALOG_H
