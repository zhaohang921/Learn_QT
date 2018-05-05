#include "choose_mode_dialog.h"
#include "ui_choose_mode_dialog.h"

chooseModeDialog::chooseModeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseModeDialog)
{
    ui->setupUi(this);

    chooseSteps = new chooseStepsDialog;
}

chooseModeDialog::~chooseModeDialog()
{
    delete ui;
    ui = nullptr;
    delete chooseSteps;
    chooseSteps = nullptr;
}

void chooseModeDialog::on_startTrain_pushButton_clicked()
{
    //选择步骤的界面出现后，把选择培训模式的界面关闭
    this->chooseModeDialog::close();
    chooseSteps->exec();

}
