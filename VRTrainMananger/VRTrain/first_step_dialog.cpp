#include "first_step_dialog.h"
#include "ui_first_step_dialog.h"

firstStepDialog::firstStepDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::firstStepDialog)
{
    ui->setupUi(this);
}

firstStepDialog::~firstStepDialog()
{
    delete ui;
}
