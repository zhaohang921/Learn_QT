#include "sixth_step_dialog.h"
#include "ui_sixth_step_dialog.h"

sixth_step_Dialog::sixth_step_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sixth_step_Dialog)
{
    ui->setupUi(this);
}

sixth_step_Dialog::~sixth_step_Dialog()
{
    delete ui;
}
