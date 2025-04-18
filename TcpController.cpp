#include "TcpController.h"

TcpController::TcpController(QObject* parent)
    : QObject(parent),
    m_tcpSocket(new QTcpSocket(this))
{
    // m_socket = new QTcpSocket(this);
    m_serverIp = "";
    m_serverPort = 0;

    connect(m_tcpSocket, &QTcpSocket::connected, this, &TcpController::onSocketConnected);
    connect(m_tcpSocket, &QTcpSocket::disconnected, this, &TcpController::onSocketDisconnected);
    connect(m_tcpSocket, &QTcpSocket::readyRead, this, &TcpController::onSocketReadyRead);
    connect(m_tcpSocket, &QTcpSocket::errorOccurred, this, &TcpController::onSocketError);
}

void TcpController::connectToServer(const QString &ip, int port)
{
    m_serverIp = ip;
    m_serverPort = port;
    m_tcpSocket->connectToHost(m_serverIp, static_cast<quint16>(m_serverPort));
}

void TcpController::disconnectFromServer()
{
    m_tcpSocket->disconnectFromHost();
}

void TcpController::sendData(const QByteArray &array)
{
    if(m_tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        m_tcpSocket->write(array);
        m_tcpSocket->flush();
    }
}

// slots
void TcpController::onSocketConnected()
{
    emit connected();
}

void TcpController::onSocketDisconnected()
{
    emit disconnected();
}

void TcpController::onSocketReadyRead()
{
    emit dataReceived(m_tcpSocket->readAll());
}

void TcpController::onSocketError(QAbstractSocket::SocketError error)
{
    Q_UNUSED(error);
    emit errorOccurred(m_tcpSocket->errorString());
}
