#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QTcpServer>

TcpServer::TcpServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);

    setFixedSize(350, 180);
    tcpPort = 6666;
    tcpServer = new QTcpServer(this);
    //connect(tcpServer, SIGNAL(newConnection()), this, SLOT(sendMessage()));
    connect(tcpServer, &QTcpServer::newConnection(), this, &TcpServer::sendMessage());
    initServer();
}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::initServer()
{
    payloadSize = 64 * 1024;

}

void TcpServer::sendMessage()
{

}
