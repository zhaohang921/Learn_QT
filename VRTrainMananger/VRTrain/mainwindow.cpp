#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chooseMode = new chooseModeDialog;
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete chooseMode;
    chooseMode = nullptr;
}

void MainWindow::on_start_pushButton_clicked()
{
    chooseMode->exec();

}
