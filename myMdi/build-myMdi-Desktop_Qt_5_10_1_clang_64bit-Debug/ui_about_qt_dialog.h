/********************************************************************************
** Form generated from reading UI file 'about_qt_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_QT_DIALOG_H
#define UI_ABOUT_QT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About_Qt_Dialog
{
public:
    QLabel *label;

    void setupUi(QDialog *About_Qt_Dialog)
    {
        if (About_Qt_Dialog->objectName().isEmpty())
            About_Qt_Dialog->setObjectName(QStringLiteral("About_Qt_Dialog"));
        About_Qt_Dialog->resize(400, 300);
        label = new QLabel(About_Qt_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 130, 60, 16));

        retranslateUi(About_Qt_Dialog);

        QMetaObject::connectSlotsByName(About_Qt_Dialog);
    } // setupUi

    void retranslateUi(QDialog *About_Qt_Dialog)
    {
        About_Qt_Dialog->setWindowTitle(QApplication::translate("About_Qt_Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("About_Qt_Dialog", "\345\205\263\344\272\216Qt\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About_Qt_Dialog: public Ui_About_Qt_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_QT_DIALOG_H
