#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include "TcpController.h"

class AppManager : public QObject
{
    Q_OBJECT
public:
    AppManager(QObject* parent = nullptr);

    void startTcpConnections(QString ip, int port);
    void stopTcpConnections();
    void sendData(const QString &data);

signals:
    void receivedMessages(const QByteArray &data);

private:
    TcpController* m_tcpController;
};

#endif // APPMANAGER_H
