#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <cstdio>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user_num = 0;
    client_num = 0;
    port_number = 1997;
    file = new QFile("Register.txt");

    connect(this->ui->btn_exit,&QPushButton::clicked,this,&MainWindow::on_btn_exit_clicked);
    connect(this->ui->btn_save,&QPushButton::clicked,this,&MainWindow::on_btn_save_clicked);
    connect(this->ui->btn_update,&QPushButton::clicked,this,&MainWindow::on_btn_update_clicked);

    file->open(QIODevice::ReadOnly |QIODevice::Text);
    QTextStream *readdst= new QTextStream(file);
    //QTextStream *readdst = new QTextStream(file,QIODevice::ReadOnly |QIODevice::Text);
    //readdst.setCodec(QTextCodec::codecForName("GB2312"));
    allusers = new user();
    conn_users = new login();
    while(!readdst->atEnd())        //读取文件中保存的用户
    {
        user_num++;
        user *p = new user();
        p->account = readdst->readLine();
        p->psw = readdst->readLine();
        p->question = readdst->readLine();
        p->answer = readdst->readLine();
        secret(p->psw);
        secret(p->answer);
        p->next = allusers->next;
        p->inout = 0;
        allusers->next = p;
        qDebug()<<p->account<<p->psw<<p->question<<p->answer<<"\n";
    }
    file->close();
    //this->m_socket = new QTcpSocket(this);
    m_server=new QTcpServer(this);
    m_server->listen(QHostAddress::Any,2001);       //服务器端口号：1997
    connect(this->m_server,SIGNAL(newConnection()),this,SLOT(on_conned()));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
}
MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_conned()
{
    login* p = new login(m_server);
    p->next = conn_users->next;
    conn_users->next = p;
    connect(p ,SIGNAL(newMessage(login*)),this,SLOT(on_readyread(login*)));
}
void MainWindow::on_disconned(){
}
void MainWindow::on_readyread(login*sender)
{
    QByteArray arr=sender->socket->readAll();
    QDataStream rdst(arr);
    QString head;
    rdst>>head;
    if(head=="reg")     //注册
    {
        rdst>>account>>psw>>question>>answer;
        QDataStream wdst(&arr,QIODevice::ReadWrite);
        wdst<<QString("reg");
        if(allusers->finduser(account))     //如果用户已存在，返回fail
            wdst<<QString("fail");
        else
        {
            user_num++;
            user* p = new user();
            p->account = account;
            p->psw = psw;
            p->question = question;
            p->answer = answer;
            p->next = allusers->next;
            p->inout = 0;
            allusers->next = p;
            wdst<<QString("ack");
        }
        wdst<<account;
        sendmessage(arr,sender->socket);    //之后应析构？
    }
    else if(head=="login")      //登录
    {
        QString ip;
        quint16 port;
        rdst>>ip>>port>>account>>psw;
        QDataStream wdst(&arr,QIODevice::ReadWrite);
        wdst<<QString("login");
        user* p =allusers->finduser(account);
        if(p )
        {
            if(p->psw==psw) //账号密码均正确
            {
                client_num++;
                p->user_port =port;
                wdst<<QString("ack")<<account;
                p->ip = ip;
                p->inout = 1;
                sender->valid = 1;
                sender->inout = 1;
                sender->account = account;
                sender->ip = ip;
                if(p->offmsg)           //用户存在离线消息
                {
                    wdst<<QString("offmsg");
                    readOffMsg(p->account,wdst);
                    p->offmsg = 0;
                }
                else wdst<<QString("nooffmsg");
            }
            else   wdst<<QString("fail")<<account;
        }
        else  wdst<<QString("none")<<account;
        sendmessage(arr,sender->socket);
    }
    else if(head=="logout")         //登出
    {
        rdst>>account;
        user * p=allusers->finduser(account);
        if(p )
        {
            client_num--;
            p->inout = 0;
            sender->inout = 0;
        }
    }
    else if(head=="find")       //找回密码
    {
        rdst>>account>>question>>answer>>psw;
        QDataStream wdst(&arr,QIODevice::ReadWrite);
        wdst<<QString("find");
        user * p=allusers->finduser(account);
        if(p )
        {
            if(p->question==question)
            {
                if(p->answer==answer)
                {
                    p->psw = psw;
                    wdst<<QString("ack");
                }
                else
                    wdst<<QString("fail");
            }
            else wdst<<QString("wrong");
        }
        else  wdst<<QString("none");
        wdst<<account;
        sendmessage(arr,sender->socket);
    }
    else if(head=="getfriend")      //获取用户列表
    {
        rdst>>account;
        QDataStream wdst(&arr,QIODevice::ReadWrite);
        user* p = allusers->next;
        wdst<<QString("friend")<<user_num-1;        //总用户数量
        while( p)
        {
            if(p->account != account)
                wdst<<p->account;
            p =p->next;
        }
        sendmessage(arr,sender->socket);
    }
    else if(head=="applyforip")     //申请IP
    {
        QString chatter;
        rdst>>account>>chatter;
        arr.clear();
        QDataStream wdst(&arr,QIODevice::ReadWrite);
        wdst<<QString("getip");
        user*p=allusers->finduser( chatter);
        if(p->inout)                //在线
            wdst<<QString("friendonline")<<p->ip<<p->user_port;
        else
            wdst<<QString("friendoff");
        sendmessage(arr,sender->socket);
    }
    else if(head=="chatmsg")        //服务器收到（离线）消息
    {
        QString msg,Sender,receiver;
        rdst>>Sender>>receiver>>msg;
        user* p=allusers->finduser(receiver);
        p->offmsg = 1;

        qDebug()<<"offmsg:"<<p->offmsg;

        writeOffMsg(Sender,receiver,msg);
    }
}
void MainWindow::on_btn_exit_clicked()
{
    on_btn_save_clicked();
    allusers->destroy();
    conn_users->destroy();
    this->close();
}
void MainWindow::sendmessage(QByteArray &arr,QTcpSocket *&client){
    client->write(arr);
}
void MainWindow::secret(QString &message)       //密码加密函数
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    std::string str = message.toStdString();
    int i = str.length();
    char *s = (char*)str.c_str();
    for(int j=0;j<i;++j)
        s[j] = s[j] ^ 0x04;
    message = QString(s);
}
void MainWindow:: writeOffMsg(QString &sender,QString &receiver,QString &msg)
{
    QString filename = receiver + QString(".txt");
    file=new QFile(filename);
    file->open(QIODevice::ReadWrite |QIODevice::Text);
    QTextStream writedst(file);
    writedst.seek(file->size());
    qDebug()<<file->size();     //输出文件大小
    writedst<<sender<<"\n";
    writedst<<msg<<"\n";
    file->close();
}
void MainWindow:: readOffMsg(QString &receiver,QDataStream &dst)
{
    QString filename = receiver + QString(".txt");
    file=new QFile(filename);
    file->open(QIODevice::ReadWrite |QIODevice::Text);
    QTextStream readdst(file);
    while(! readdst.atEnd())
    {
        dst<<(readdst.readLine());
        dst<<(readdst.readLine());
    }
    file->close();
    file->open(QFile::WriteOnly|QFile::Truncate);//用来清空文件
    file->close();
    QFile::remove(filename);
}

void MainWindow::on_btn_save_clicked()
{
    file = new QFile("Register.txt");
    file->open(QFile::WriteOnly|QFile::Truncate);//用来清空文件
    file->close();
    file->open(QIODevice::WriteOnly |QIODevice::Text);
    QTextStream writedst(file);
    user * p=allusers->next;
    for( ; p ;p=p->next)                //保存用户信息
    {
        secret(p->psw);
        secret(p->answer);
        qDebug()<<p->account<<p->psw<<p->question<<p->answer;
        writedst<<p->account<<"\n";
        writedst<<p->psw<<"\n";
        writedst<<p->question<<"\n";
        writedst<<p->answer<<"\n";
        secret(p->psw);
        secret(p->answer);
    }
    file->close();
}
void MainWindow::on_btn_update_clicked()        //刷新用户信息
{
    ui->list_off->clear();
    ui->list_online->clear();
    user * p=allusers->next;
    for( ; p ;p=p->next)
    {
        if(p->inout)
            ui->list_online->addItem(p->account+": "+p->ip);
        else
            ui->list_off->addItem(p->account);
    }
}

