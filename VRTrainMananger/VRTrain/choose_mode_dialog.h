#ifndef CHOOSE_MODE_DIALOG_H
#define CHOOSE_MODE_DIALOG_H

#include <QDialog>
#include "choose_steps_dialog.h"

namespace Ui {
class chooseModeDialog;
}

class chooseModeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chooseModeDialog(QWidget *parent = 0);
    ~chooseModeDialog();

private slots:
    void on_startTrain_pushButton_clicked();

private:
    Ui::chooseModeDialog *ui;
    chooseStepsDialog *chooseSteps;
};

#endif // CHOOSEMODEDIALOG_H
