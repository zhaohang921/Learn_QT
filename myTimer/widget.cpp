#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //开启了三个定时器，分别返回了它们的id，这个id用来区分不同的定时器
    //定时器的时间单位是毫秒。每当一个定时器溢出时，都会调用定时器事件处理函数
    id1 = startTimer(1000);
    id2 = startTimer(2000);
    id3 = startTimer(10000);

    //创建了一个定时器，并将其溢出信号和更新槽关联起来，最后使用start()函数来开启定时器
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::timerUpdate);
    timer->start(1000);

    //使用qsrand()设置一个不同的初值。这里使用了QTime类的secsTo()函数，
    //它表示两个时间点之间所包含的秒数，比如代码中就是指从零点整到当前时间所经过的秒数
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

}

Widget::~Widget()
{
    delete ui;

}

void Widget::timerEvent(QTimerEvent *e)
{
    //使用timerId()函数返回了溢出的定时器的id，然后根据该id来判断是哪个定时器溢出了，并进行相应的处理
    //每当第一个定时器溢出时都产生一个小于10的随机数；
    //当第二个定时器溢出时，就更改标签的文本；
    //当第三个定时器溢出时则退出应用程序。
    if (e->timerId() == id1){
        ui->label->setText(tr("%1").arg(qrand()%10));
    } else if (e->timerId() == id2){
        ui->label_2->setText(tr("Hello, World!"));
    } else {
        qApp->quit();
    }
}

void Widget::timerUpdate()
{

    //获取系统现在的时间
    QDateTime time = QDateTime::currentDateTime();
    //设置系统时间显示格式
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    qDebug() << "time:" << str ;
    //在标签上显示时间
    ui->lineEdit->setText(str);
    // 产生300以内的正整数
    int rand = qrand()%300;
    ui->lineEdit->move(rand, rand);
}
