#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "registerdialog.h"
#include "findpswdialog.h"
#include <QHostInfo>
#include <QHostAddress>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QMainWindow>
#include <QMovie>
#include <QString>
#include <QDialog>
#include <QTcpServer>
#include <QUdpSocket>
#include <QDebug>
#include <QListWidgetItem>
#include <QFileDialog>
#include <string>
#include <QTextCodec>
#include <QStringList>
#include <QFileInfo>
#include <QHostAddress>
#include <QUrl>
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include <user.h>
#include <login.h>

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    RegisterDialog *reg_dialog;
    findpswDialog  *find_dialog;
    QFileDialog *fileDialog;
    QString account, psw,myaccount,serverip;
    QString localip,current_chatter,chatter_ip,chatter_udpip;
    QByteArray arr, dataarr;
    QFile *file_rw;
    int conn_or_not,chatterState,connectState,state;
    int msg_file;
    qint64 sequenceSent,sequenceAccepted,   segLength,  sequencetemp;
    qint64 winMax,winThreshold, winLen, begin,end,rtt,tail;
    qint64 ackcount;
    QTimer *timers;
    QByteArray *arrbuf;
    quint16 myport, chatter_port,chatter_udpport,senderPort,receiverPort,port;
    QHostAddress hostSender,hostReceiver,chatterHost,host;
    user* allusers;
    login* conn_users;
    QTcpSocket *current_socket;
    QString file_full,file_name;
    QTimer *timer;
    QTime t;
    QDateTime start, endup;
    //QStringList filenames;
    void reconnect();
    void DisplayUsers(user*p);
signals:
    void emitlogin();
private slots:
    void on_connected();
    void on_discon();
    void on_btn_send_clicked();
    void on_btn_close_clicked();
    void on_action_register_triggered();
    void on_action_find_triggered();
    void on_readyread();
    void on_readyread(login*);
    void sendmessage(QByteArray &arr);
    void sendmessage(QByteArray &arr,QTcpSocket *chatter);
    void on_btn_login_clicked();
    void login_succeed();
    void logout_succeed();
    void on_btn_off_clicked();
    void on_btn_getfriend_clicked();
    void on_list_friend_itemDoubleClicked(QListWidgetItem *item);
    void chatted_connected();
    void connect_to_chatter( );
    void chatting_connected();
    void on_readychatting();
    void chatting_dis();
    void on_btn_file_clicked();
    void readPendingDatagrams();
    void handleMsg();
    void dialogSave();
    void sendFile();
    void sendimg();
    void receiveFile();
    void on_resend();
    void reSend();
    void send();
private :
    QTcpSocket *m_socket,*chat_socket,*chatted_socket;
    QTcpServer *chat_server;
    QUdpSocket *udpsender,*udpreceiver;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
