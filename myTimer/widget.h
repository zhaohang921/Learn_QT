#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void timerEvent(QTimerEvent *e);
private slots:
    void timerUpdate();

private:
    Ui::Widget *ui;

    int id1, id2, id3;
};

#endif // WIDGET_H
