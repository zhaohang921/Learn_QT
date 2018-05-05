#ifndef SECOND_STEP_DIALOG_H
#define SECOND_STEP_DIALOG_H

#include <QDialog>

namespace Ui {
class secondStepDialog;
}

class secondStepDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secondStepDialog(QWidget *parent = 0);
    ~secondStepDialog();

private:
    Ui::secondStepDialog *ui;
};

#endif // SECONDSTEPDIALOG_H
