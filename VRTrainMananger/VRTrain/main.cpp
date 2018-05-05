#include "mainwindow.h"
#include <QApplication>
#include "login_dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    loginDialog dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    } else {
        return 0;
    }


}
