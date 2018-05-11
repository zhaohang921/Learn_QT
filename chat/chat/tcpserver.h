#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>

namespace Ui {
class TcpServer;
}

class QTcpServer;

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();
    void initServer();

private:
    Ui::TcpServer *ui;

    qint16 tcpPort;
    QTcpServer tcpServer;

private:
    void sendMessage();
};

#endif // TCPSERVER_H
