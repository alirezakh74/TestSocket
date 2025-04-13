#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_appManager(new AppManager(this))
{
    ui->setupUi(this);

    connect(m_appManager, &AppManager::receivedMessages, this, &MainWindow::receivedMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_IpAddressLineEdit_textChanged(const QString &arg1)
{
}


void MainWindow::on_ConnectButton_clicked()
{
    if("Connect" == ui->ConnectButton->text())
    {
        QString ip = ui->IpAddressLineEdit->text();
        int port = ui->PortSpinBox->value();
        m_appManager->startTcpConnections(ip, port);
        ui->ConnectButton->setText("Disconnect");
    }
    else
    {
        m_appManager->stopTcpConnections();
        ui->ConnectButton->setText("Connect");
    }
}


void MainWindow::on_PortSpinBox_valueChanged(int arg1)
{

}


void MainWindow::on_SendMessagePushButton_clicked()
{
    QString message = ui->MessageTextEdit->toPlainText();
    m_appManager->sendData(message);
}

void MainWindow::receivedMessage(const QByteArray &data)
{
    ui->ReceivedTextBrowser->setPlainText(QString::fromStdString(data.toStdString()));
}

