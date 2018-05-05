#ifndef FIRST_STEP_DIALOG_H
#define FIRST_STEP_DIALOG_H

#include <QDialog>

namespace Ui {
class firstStepDialog;
}

class firstStepDialog : public QDialog
{
    Q_OBJECT

public:
    explicit firstStepDialog(QWidget *parent = 0);
    ~firstStepDialog();

private:
    Ui::firstStepDialog *ui;
};

#endif // FIRSTSTEPDIALOG_H
