#ifndef FOURTH_STEP_DIALOG_H
#define FOURTH_STEP_DIALOG_H

#include <QDialog>

namespace Ui {
class fourth_step_Dialog;
}

class fourth_step_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit fourth_step_Dialog(QWidget *parent = 0);
    ~fourth_step_Dialog();

private:
    Ui::fourth_step_Dialog *ui;
};

#endif // FOURTH_STEP_DIALOG_H
