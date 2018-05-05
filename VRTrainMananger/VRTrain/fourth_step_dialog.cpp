#include "fourth_step_dialog.h"
#include "ui_fourth_step_dialog.h"

fourth_step_Dialog::fourth_step_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourth_step_Dialog)
{
    ui->setupUi(this);
}

fourth_step_Dialog::~fourth_step_Dialog()
{
    delete ui;
}
