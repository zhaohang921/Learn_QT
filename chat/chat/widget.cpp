#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    port = 45454;
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
    // sendMessage广播用户登陆信息
    sendMessage(NewParticipant);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::newParticipant(QString userName, QString localHostName, QString ipAddress)
{
    // 使用主机名来判断该用户是否已经加入到用户列表中
    bool isEmpty = ui->userTableWidget->findItems(localHostName, Qt::MatchExactly).isEmpty();
    if (isEmpty){
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

        ui->userTableWidget->insertRow(0);
        ui->userTableWidget->setItem(0, 0, user);
        ui->userTableWidget->setItem(0, 1, host);
        ui->userTableWidget->setItem(0, 2, ip);

        ui->messageBrowser->setTextColor(Qt::gray);
        ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
        ui->messageBrowser->append(tr("%1在线!").arg(userName));

        ui->userNumLabel->setText(tr("在线人数:%1").arg(ui->userTableWidget->rowCount()));

        sendMessage(NewParticipant);
    }
}

void Widget::participantLeft(QString userName, QString localHostName, QString time)
{
    int rowNum = ui->userTableWidget->findItems(localHostName,
                                                Qt::MatchExactly).first()->row();
    ui->userTableWidget->removeRow(rowNum);
    ui->messageBrowser->setTextColor(Qt::gray);
    ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
    ui->messageBrowser->append(tr("%1于%2离开！").arg(userName).arg(time));
    ui->userNumLabel->setText(tr("在线人数:%1").arg(ui->userTableWidget->rowCount()));
}

// 广播用户登陆信息
void Widget::sendMessage(MessageType type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();
    // 首先向要发送的数据中写入信息类型type，用户名和主机名
    out << type << getUserName() << localHostName;
    switch(type){
    case Message:
        // 普通的聊天信息，先判断是否为空
        if (ui->messageTextEdit->toPlainText() == ""){
            QMessageBox::warning(0, tr("警告"),
                                 tr("发送内容不能为空"), QMessageBox::Ok);
            return;
        }
        // 向发送的数据中写入本机的IP地址和输入的消息文本
        out << address << getMessage();
        ui->messageBrowser->verticalScrollBar()
                ->setValue(ui->messageBrowser->verticalScrollBar()->maximum());
        break;

    case NewParticipant:
        // 对于新加入的用户，只是简单地向数据中写入IP地址
        out << address;
        break;

    case ParticipantLeft:
        break;

    case FileName:
        break;

    case Refuse:
        break;
    }
    // 进行UDP广播
    udpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, port);
}

QString Widget::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list){
        if (address.protocol() == QAbstractSocket::IPv4Protocol){
            return address.toString();
        }
    }
    return 0;
}

QString Widget::getUserName()
{
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables){
        int index = environment.indexOf(QRegExp(string));
        if (index != -1){
            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2){
                return stringList.at(1);
                break;
            }
        }
    }
    return "unknown";
}

QString Widget::getMessage()
{
    QString msg = ui->messageTextEdit->toHtml();
    ui->messageTextEdit->clear();
    ui->messageTextEdit->setFocus();
    return msg;
}

// 接收UDP广播发送来的数据
void Widget::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram, QIODevice::ReadOnly);
        int messageType;
        // 首先获得消息的类型
        in >> messageType;
        QString userName, localHostName, ipAddress, message;
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch(messageType){
        case Message:
            in >> userName >> localHostName >> ipAddress >> message;
            ui->messageBrowser->setTextColor(Qt::blue);
            ui->messageBrowser->setCurrentFont(QFont("Times New Roman", 12));
            ui->messageBrowser->append("[" + userName + "]" + time);
            ui->messageBrowser->append(message);
            break;

        case NewParticipant:
            in >> userName >> localHostName >> ipAddress;
            newParticipant(userName, localHostName, time);
            break;

        case ParticipantLeft:
            in >> userName >> localHostName;
            participantLeft(userName, localHostName, time);
            break;

        case FileName:
            break;

        case Refuse:
            break;
        }
    }
}

void Widget::on_sendButton_clicked()
{
    sendMessage(Message);
}
