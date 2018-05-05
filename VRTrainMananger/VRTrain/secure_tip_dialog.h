#ifndef SECURE_TIP_DIALOG_H
#define SECURE_TIP_DIALOG_H

#include <QDialog>

namespace Ui {
class secureTipDialog;
}

class secureTipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secureTipDialog(QWidget *parent = 0);
    ~secureTipDialog();

private:
    Ui::secureTipDialog *ui;
};

#endif // SECURETIPDIALOG_H
