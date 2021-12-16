#include "login.h"

login::login(QTcpServer*server)
{
    next =0;
    inout =1;
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
void login:: on_connected()
{
    emit newMessage(this);
}
void login::on_disconned()
{
    inout = 0;
}
login* login::find(QString &account)
{
    login *p = this->next;
    for(; p; p=p->next)
    {
        if(p->account==account)
            return p;
    }
    return 0;
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
login::~login()
{
    if(socket)
        delete socket;
}
