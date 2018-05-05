#include "secure_tip_dialog.h"
#include "ui_secure_tip_dialog.h"

secureTipDialog::secureTipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secureTipDialog)
{
    ui->setupUi(this);
}

secureTipDialog::~secureTipDialog()
{
    delete ui;
}
