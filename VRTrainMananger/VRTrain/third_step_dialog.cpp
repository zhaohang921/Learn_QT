#include "third_step_dialog.h"
#include "ui_third_step_dialog.h"

third_step_Dialog::third_step_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::third_step_Dialog)
{
    ui->setupUi(this);
}

third_step_Dialog::~third_step_Dialog()
{
    delete ui;
}
