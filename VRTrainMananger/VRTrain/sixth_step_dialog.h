#ifndef SIXTH_STEP_DIALOG_H
#define SIXTH_STEP_DIALOG_H

#include <QDialog>

namespace Ui {
class sixth_step_Dialog;
}

class sixth_step_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sixth_step_Dialog(QWidget *parent = 0);
    ~sixth_step_Dialog();

private:
    Ui::sixth_step_Dialog *ui;
};

#endif // SIXTH_STEP_DIALOG_H
