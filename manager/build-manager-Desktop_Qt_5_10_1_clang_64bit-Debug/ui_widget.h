/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *manageBtn;
    QPushButton *chartBtn;
    QPushButton *passwordBtn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QStackedWidget *stackedWidget_2;
    QWidget *managePage;
    QListWidget *dailyList;
    QToolBox *toolBox;
    QWidget *page_3;
    QLabel *label_2;
    QComboBox *sellTypeComboBox;
    QLineEdit *sellPriceLineEdit;
    QSpinBox *sellNumSpinBox;
    QPushButton *sellOkBtn;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *sellBrandComboBox;
    QLabel *label_7;
    QLabel *sellLastNumLabel;
    QLineEdit *sellSumLineEdit;
    QLabel *label_9;
    QPushButton *sellCancelBtn;
    QWidget *page_5;
    QWidget *page_4;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(750, 500);
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 10, 611, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        manageBtn = new QPushButton(horizontalLayoutWidget);
        manageBtn->setObjectName(QStringLiteral("manageBtn"));

        horizontalLayout->addWidget(manageBtn);

        chartBtn = new QPushButton(horizontalLayoutWidget);
        chartBtn->setObjectName(QStringLiteral("chartBtn"));

        horizontalLayout->addWidget(chartBtn);

        passwordBtn = new QPushButton(horizontalLayoutWidget);
        passwordBtn->setObjectName(QStringLiteral("passwordBtn"));

        horizontalLayout->addWidget(passwordBtn);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 0, 0));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        stackedWidget_2 = new QStackedWidget(Widget);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(20, 90, 700, 410));
        stackedWidget_2->setFrameShape(QFrame::NoFrame);
        managePage = new QWidget();
        managePage->setObjectName(QStringLiteral("managePage"));
        dailyList = new QListWidget(managePage);
        dailyList->setObjectName(QStringLiteral("dailyList"));
        dailyList->setGeometry(QRect(380, 20, 311, 371));
        toolBox = new QToolBox(managePage);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(10, 20, 351, 371));
        toolBox->setFrameShape(QFrame::WinPanel);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 347, 293));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 20, 31, 16));
        sellTypeComboBox = new QComboBox(page_3);
        sellTypeComboBox->setObjectName(QStringLiteral("sellTypeComboBox"));
        sellTypeComboBox->setGeometry(QRect(80, 20, 211, 26));
        sellPriceLineEdit = new QLineEdit(page_3);
        sellPriceLineEdit->setObjectName(QStringLiteral("sellPriceLineEdit"));
        sellPriceLineEdit->setGeometry(QRect(80, 100, 111, 21));
        sellNumSpinBox = new QSpinBox(page_3);
        sellNumSpinBox->setObjectName(QStringLiteral("sellNumSpinBox"));
        sellNumSpinBox->setGeometry(QRect(80, 140, 48, 24));
        sellOkBtn = new QPushButton(page_3);
        sellOkBtn->setObjectName(QStringLiteral("sellOkBtn"));
        sellOkBtn->setGeometry(QRect(40, 230, 113, 32));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 60, 31, 16));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 100, 31, 16));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 140, 31, 16));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 180, 31, 16));
        sellBrandComboBox = new QComboBox(page_3);
        sellBrandComboBox->setObjectName(QStringLiteral("sellBrandComboBox"));
        sellBrandComboBox->setGeometry(QRect(80, 60, 211, 26));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(200, 100, 31, 16));
        sellLastNumLabel = new QLabel(page_3);
        sellLastNumLabel->setObjectName(QStringLiteral("sellLastNumLabel"));
        sellLastNumLabel->setGeometry(QRect(140, 140, 111, 16));
        sellSumLineEdit = new QLineEdit(page_3);
        sellSumLineEdit->setObjectName(QStringLiteral("sellSumLineEdit"));
        sellSumLineEdit->setGeometry(QRect(80, 180, 111, 21));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(200, 180, 31, 16));
        sellCancelBtn = new QPushButton(page_3);
        sellCancelBtn->setObjectName(QStringLiteral("sellCancelBtn"));
        sellCancelBtn->setGeometry(QRect(190, 230, 113, 32));
        toolBox->addItem(page_3, QString::fromUtf8("\345\207\272\345\224\256\345\225\206\345\223\201"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 347, 293));
        toolBox->addItem(page_5, QString::fromUtf8("\345\267\262\346\234\211\345\225\206\345\223\201\345\205\245\345\272\223"));
        stackedWidget_2->addWidget(managePage);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget_2->addWidget(page_4);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 711, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\225\260\346\215\256\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        manageBtn->setText(QApplication::translate("Widget", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        chartBtn->setText(QApplication::translate("Widget", "\351\224\200\345\224\256\347\273\237\350\256\241", nullptr));
        passwordBtn->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_2->setText(QApplication::translate("Widget", "\347\261\273\345\236\213\357\274\232", nullptr));
        sellOkBtn->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", nullptr));
        label_3->setText(QApplication::translate("Widget", "\345\223\201\347\211\214\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Widget", "\345\215\225\344\273\267\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Widget", "\346\225\260\351\207\217\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Widget", "\351\207\221\351\242\235\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Widget", "\345\205\203", nullptr));
        sellLastNumLabel->setText(QApplication::translate("Widget", "\345\211\251\344\275\231\346\225\260\351\207\217\357\274\232000", nullptr));
        label_9->setText(QApplication::translate("Widget", "\345\205\203", nullptr));
        sellCancelBtn->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("Widget", "\345\207\272\345\224\256\345\225\206\345\223\201", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("Widget", "\345\267\262\346\234\211\345\225\206\345\223\201\345\205\245\345\272\223", nullptr));
        label->setText(QApplication::translate("Widget", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
