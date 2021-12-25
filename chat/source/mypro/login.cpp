#include "login.h"

login::login(QTcpServer*server)
{
    next =0;
    inout =0;
    valid = 0;
    socket = new QTcpSocket(this);
    socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,SLOT(on_connected()) );
    connect(socket,SIGNAL(disconnected()),this,SLOT(on_disconned()));
    qDebug()<<socket->peerName()<<socket->peerAddress()<<socket->peerPort();
}
login::login()
{
    next =0;
    inout =0;
    valid = 0;
    socket = 0;
}
void login:: destroy()
{
    login*p = this->next, *pp=p;
    while(pp)
    {
        pp=p->next;
        delete p;
        p = pp;
    }
    this->next = 0;
}
void login:: on_connected()
{
    emit newMessage(this);
}
void login::on_disconned()
{
}
login::~login()
{
    delete socket;
}
