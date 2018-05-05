#include "fifth_step_dialog.h"
#include "ui_fifth_step_dialog.h"

fifth_step_Dialog::fifth_step_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fifth_step_Dialog)
{
    ui->setupUi(this);
}

fifth_step_Dialog::~fifth_step_Dialog()
{
    delete ui;
}
