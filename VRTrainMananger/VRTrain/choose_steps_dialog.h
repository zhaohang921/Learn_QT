#ifndef CHOOSE_STEPS_DIALOG_H
#define CHOOSE_STEPS_DIALOG_H

#include <QDialog>
#include "first_step_dialog.h"
#include "second_step_dialog.h"
#include "third_step_dialog.h"
#include "fourth_step_dialog.h"
#include "fifth_step_dialog.h"
#include "sixth_step_dialog.h"

namespace Ui {
class chooseStepsDialog;
}

class chooseStepsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chooseStepsDialog(QWidget *parent = 0);
    ~chooseStepsDialog();

private slots:
    void on_firstStep_pushButton_clicked();

    void on_secondStep_pushButton_clicked();

    void on_thirdStep_pushButton_clicked();

    void on_fourthStep_pushButton_clicked();

    void on_fifthStep_pushButton_clicked();

    void on_sixthStep_pushButton_clicked();

private:
    Ui::chooseStepsDialog *ui;

};

#endif // CHOOSESTEPSDIALOG_H
