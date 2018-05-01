#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

class QLineEdit;
class QDialog;
class QLabel;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void newFile();
    bool maybeSave(); //判断是否需要保存
    bool save();
    bool saveAs();
    bool saveFile(const QString& fileName);
    bool loadFile(const QString& fileName);

protected:
    void closeEvent(QCloseEvent *event); //关闭事件


private slots:
    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_action_Save_triggered();

    void on_action_SaveAs_triggered();

    void on_action_Close_triggered();

    void on_action_Exit_triggered();

    void on_action_Undo_triggered();

    void on_action_Cut_triggered();

    void on_action_Copy_triggered();

    void on_action_Paste_triggered();

    void showFindText();
    void on_action_Find_triggered();

private:
    Ui::MainWindow *ui;

    QLineEdit *findLineEdit;
    QDialog *findDlg;
    QLabel *statusLabel;

    bool isUntitled;  //为true表示文件没有保存过
    QString curFile;  //保存当前文件的路径
};

#endif // MAINWINDOW_H
