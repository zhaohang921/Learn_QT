#include "second_step_dialog.h"
#include "ui_second_step_dialog.h"

secondStepDialog::secondStepDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondStepDialog)
{
    ui->setupUi(this);
}

secondStepDialog::~secondStepDialog()
{
    delete ui;
}
