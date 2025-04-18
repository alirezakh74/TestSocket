#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AppManager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_IpAddressLineEdit_textChanged(const QString &arg1);

    void on_PortSpinBox_valueChanged(int arg1);

    void on_ConnectButton_clicked();

    void on_SendMessagePushButton_clicked();

    void receivedMessage(const QByteArray &data);

private:
    Ui::MainWindow *ui;
    AppManager* m_appManager;
};
#endif // MAINWINDOW_H
