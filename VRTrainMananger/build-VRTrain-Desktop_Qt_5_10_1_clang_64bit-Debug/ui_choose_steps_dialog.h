/********************************************************************************
** Form generated from reading UI file 'choose_steps_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_STEPS_DIALOG_H
#define UI_CHOOSE_STEPS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooseStepsDialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *firstStep_pushButton;
    QPushButton *secondStep_pushButton;
    QPushButton *thirdStep_pushButton;
    QPushButton *fourthStep_pushButton;
    QPushButton *fifthStep_pushButton;
    QPushButton *sixthStep_pushButton;

    void setupUi(QDialog *chooseStepsDialog)
    {
        if (chooseStepsDialog->objectName().isEmpty())
            chooseStepsDialog->setObjectName(QStringLiteral("chooseStepsDialog"));
        chooseStepsDialog->resize(400, 300);
        formLayoutWidget = new QWidget(chooseStepsDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 90, 291, 101));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        firstStep_pushButton = new QPushButton(formLayoutWidget);
        firstStep_pushButton->setObjectName(QStringLiteral("firstStep_pushButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, firstStep_pushButton);

        secondStep_pushButton = new QPushButton(formLayoutWidget);
        secondStep_pushButton->setObjectName(QStringLiteral("secondStep_pushButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, secondStep_pushButton);

        thirdStep_pushButton = new QPushButton(formLayoutWidget);
        thirdStep_pushButton->setObjectName(QStringLiteral("thirdStep_pushButton"));

        formLayout->setWidget(2, QFormLayout::LabelRole, thirdStep_pushButton);

        fourthStep_pushButton = new QPushButton(formLayoutWidget);
        fourthStep_pushButton->setObjectName(QStringLiteral("fourthStep_pushButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fourthStep_pushButton);

        fifthStep_pushButton = new QPushButton(formLayoutWidget);
        fifthStep_pushButton->setObjectName(QStringLiteral("fifthStep_pushButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fifthStep_pushButton);

        sixthStep_pushButton = new QPushButton(formLayoutWidget);
        sixthStep_pushButton->setObjectName(QStringLiteral("sixthStep_pushButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sixthStep_pushButton);


        retranslateUi(chooseStepsDialog);

        QMetaObject::connectSlotsByName(chooseStepsDialog);
    } // setupUi

    void retranslateUi(QDialog *chooseStepsDialog)
    {
        chooseStepsDialog->setWindowTitle(QApplication::translate("chooseStepsDialog", "\351\200\211\346\213\251\345\237\271\350\256\255\346\255\245\351\252\244", nullptr));
        firstStep_pushButton->setText(QApplication::translate("chooseStepsDialog", "\347\254\254\344\270\200\346\255\245\357\274\232\347\231\273\346\234\272\345\211\215\345\207\206\345\244\207", nullptr));
        secondStep_pushButton->setText(QApplication::translate("chooseStepsDialog", "\347\254\254\344\272\214\346\255\245\357\274\232\346\213\206\345\215\270\344\277\235\346\212\244\347\275\251", nullptr));
        thirdStep_pushButton->setText(QApplication::translate("chooseStepsDialog", "\347\254\254\344\270\211\346\255\245\357\274\232\346\236\266\350\256\276\345\257\271\344\270\255\344\273\252", nullptr));
        fourthStep_pushButton->setText(QApplication::translate("chooseStepsDialog", "\347\254\254\345\233\233\346\255\245\357\274\232\351\207\207\351\233\206\346\225\260\346\215\256", nullptr));
        fifthStep_pushButton->setText(QApplication::translate("chooseStepsDialog", "\347\254\254\344\272\224\346\255\245\357\274\232\350\260\203\346\225\264\344\275\215\347\275\256", nullptr));
        sixthStep_pushButton->setText(QApplication::translate("chooseStepsDialog", "\347\254\254\345\205\255\346\255\245\357\274\232\346\225\264\347\220\206\347\216\260\345\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chooseStepsDialog: public Ui_chooseStepsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_STEPS_DIALOG_H
