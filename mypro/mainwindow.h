#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "user.h"
#include <login.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <QDebug>
#include <QTextCodec>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    int client_num,user_num;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void sendmessage(QByteArray &arr,QTcpSocket *&client);
    QString account,psw,question,answer;
    QByteArray arr;
    QFile *file;
    user *allusers;
    login *conn_users;
    user * finduser(QString &account);
    quint16 port_number;
private :
    QTcpServer * m_server;
    //QTcpSocket * m_socket;
    Ui::MainWindow *ui;
private slots:
    void on_conned();
    void on_disconned();
    void on_readyread(login*);
    void on_btn_exit_clicked();
    void secret(QString &);
    void writeOffMsg(QString &sender,QString &receiver,QString &msg);
    void readOffMsg(QString &receiver,QDataStream &dst);
    void on_btn_save_clicked();
    void on_btn_update_clicked();
};
#endif // MAINWINDOW_H

