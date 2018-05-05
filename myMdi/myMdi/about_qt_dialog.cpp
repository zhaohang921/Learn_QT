#include "about_qt_dialog.h"
#include "ui_about_qt_dialog.h"

About_Qt_Dialog::About_Qt_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_Qt_Dialog)
{
    ui->setupUi(this);
}

About_Qt_Dialog::~About_Qt_Dialog()
{
    delete ui;
}
