#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDomElement>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    enum DateTimeType{Time, Date, DateTime};
    QString getDateTime(DateTimeType type);

private slots:
    void on_sellTypeComboBox_currentIndexChanged(QString type);

    void on_sellBrandComboBox_currentTextChanged(QString brand);

    void on_sellNumSpinBox_valueChanged(int value);

    void on_sellCancelBtn_clicked();

    void on_sellOkBtn_clicked();

private:
    bool docRead();
    bool docWrite();
    void writeXml();
    void createNodes(QDomElement &date);
    void showDailyList();

private:
    Ui::Widget *ui;
    QDomDocument doc;
};

#endif // WIDGET_H
