#ifndef FIFTH_STEP_DIALOG_H
#define FIFTH_STEP_DIALOG_H

#include <QDialog>

namespace Ui {
class fifth_step_Dialog;
}

class fifth_step_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit fifth_step_Dialog(QWidget *parent = 0);
    ~fifth_step_Dialog();

private:
    Ui::fifth_step_Dialog *ui;
};

#endif // FIFTH_STEP_DIALOG_H
