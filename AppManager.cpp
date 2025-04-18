#include "AppManager.h"

AppManager::AppManager(QObject* parent)
 : QObject(parent),
    m_tcpController( new TcpController(this))
{}

void AppManager::startTcpConnections(QString ip, int port)
{
    m_tcpController->connectToServer(ip, port);

    connect(m_tcpController, &TcpController::dataReceived, this, &AppManager::receivedMessages);
}

void AppManager::stopTcpConnections()
{
    m_tcpController->disconnectFromServer();
}

void AppManager::sendData(const QString &data)
{
    m_tcpController->sendData(data.toUtf8());
}
