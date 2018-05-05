#include "choose_steps_dialog.h"
#include "ui_choose_steps_dialog.h"

chooseStepsDialog::chooseStepsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseStepsDialog)
{
    ui->setupUi(this);
}

chooseStepsDialog::~chooseStepsDialog()
{
    delete ui;
}

void chooseStepsDialog::on_firstStep_pushButton_clicked()
{
    firstStepDialog first;
    first.exec();
}

void chooseStepsDialog::on_secondStep_pushButton_clicked()
{
    secondStepDialog second;
    second.exec();
}

void chooseStepsDialog::on_thirdStep_pushButton_clicked()
{
    third_step_Dialog third;
    third.exec();
}

void chooseStepsDialog::on_fourthStep_pushButton_clicked()
{
    fourth_step_Dialog fourth;
    fourth.exec();
}

void chooseStepsDialog::on_fifthStep_pushButton_clicked()
{
    fifth_step_Dialog fifth;
    fifth.exec();
}

void chooseStepsDialog::on_sixthStep_pushButton_clicked()
{
    sixth_step_Dialog sixth;
    sixth.exec();
}
