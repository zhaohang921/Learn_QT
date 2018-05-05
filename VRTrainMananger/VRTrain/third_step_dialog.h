#ifndef THIRD_STEP_DIALOG_H
#define THIRD_STEP_DIALOG_H

#include <QDialog>

namespace Ui {
class third_step_Dialog;
}

class third_step_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit third_step_Dialog(QWidget *parent = 0);
    ~third_step_Dialog();

private:
    Ui::third_step_Dialog *ui;
};

#endif // THIRD_STEP_DIALOG_H
