#ifndef ABOUT_QT_DIALOG_H
#define ABOUT_QT_DIALOG_H

#include <QDialog>

namespace Ui {
class About_Qt_Dialog;
}

class About_Qt_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit About_Qt_Dialog(QWidget *parent = 0);
    ~About_Qt_Dialog();

private:
    Ui::About_Qt_Dialog *ui;
};

#endif // ABOUT_QT_DIALOG_H
