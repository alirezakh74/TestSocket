#ifndef TCPCONTROLLER_H
#define TCPCONTROLLER_H

#include <QObject>
#include <QTcpSocket>

class TcpController : public QObject
{
    Q_OBJECT
public:
    TcpController(QObject* parent = nullptr);

    // public functions
    void connectToServer(const QString &ip, int port);
    void disconnectFromServer();
    void sendData(const QByteArray &array);
    //void receivedData();

signals:
    // Signals to notify AppManager
    void connected();
    void disconnected();
    void dataReceived(const QByteArray &data);
    void errorOccurred(const QString &error);

private slots:
    // Internal socket handling
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketError(QAbstractSocket::SocketError error);

private:
    QTcpSocket* m_tcpSocket;
    QString m_serverIp;
    int m_serverPort;
};

#endif // TCPCONTROLLER_H
