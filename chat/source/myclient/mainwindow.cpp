#include "mainwindow.h"
#include "registerdialog.h"
#include "findpswdialog.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    winMax = 100;
    winThreshold = 32;
    winLen = 1;                 //拥塞窗口长度
    end =  winLen;
    rtt = 1;
    timers = new QTimer[winMax+1];
    arrbuf = new QByteArray[winMax+1];
    reg_dialog = 0;
    find_dialog = 0;
    fileDialog = 0;
    conn_or_not = 0;
    chatterState = 0;
    msg_file = 1;
    allusers = new user();
    conn_users = new login();
    conn_users->next = 0;
    sequenceAccepted = 0;
    sequenceSent = 0;
    segLength = 1400;
    tail = 0;
    //tail = 0x7fffffffffffffff;
    state = 0;
    senderPort = receiverPort = 0;
    serverip = QString("127.0.0.1");        //本地服务器
    this->ui->msg_list->setIconSize(QSize(200, 200));

    connect(this->ui->actionregister,&QAction::triggered,this,&MainWindow::on_action_register_triggered);
    connect(this->ui->actionfoget,&QAction::triggered,this,&MainWindow::on_action_find_triggered);
    connect(this->ui->btn_send,&QPushButton::clicked,this,&MainWindow::on_btn_send_clicked);
    connect(this->ui->btn_getfriend,&QPushButton::clicked,this,&MainWindow::on_btn_getfriend_clicked);
    connect(this->ui->btn_file,&QPushButton::clicked,this,&MainWindow::on_btn_file_clicked);
    connect(this->ui->btn_img,&QPushButton::clicked,this,&MainWindow::sendimg);

    for(int i=0;i<=winMax;++i)
        connect(timers+i,SIGNAL(timeout()),this,SLOT(on_resend()));     //传输超时重发
    this->m_socket=new QTcpSocket(this);            //与服务器的socket
    this->chat_socket = new QTcpSocket(this);       //与聊天对象的socket
    this->current_socket = new QTcpSocket(this);    //当前socket，变量
    this->chat_server=new QTcpServer(this);         //当前TCP的连接口
    this->udpreceiver = new QUdpSocket(this);       //传输文件用
    this->udpsender = new QUdpSocket(this);

    chat_server->listen(QHostAddress::Any,0);
    myport = chat_server->serverPort();

    connect(this->m_socket,SIGNAL(connected()),this,SLOT(on_connected()));
    connect(this->m_socket,SIGNAL(disconnected()),this,SLOT(on_discon()));
    connect(this->chat_server,SIGNAL(newConnection()),this,SLOT(chatted_connected()));
    connect(this->chat_socket,SIGNAL(connected()),this,SLOT(chatting_connected()));
    logout_succeed();
    QString localHostName = QHostInfo::localHostName();     //Returns this machine's host name
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address,info.addresses())
    {
         if(address.protocol() == QAbstractSocket::IPv4Protocol)
            localip = address.toString();
    }
    qDebug()<<localip<<myport;      //show IP and Port

    hostReceiver.setAddress(localip);
    udpreceiver->bind(hostReceiver,receiverPort);       //设置本地ip地址的端口
    receiverPort = udpreceiver->localPort();

    connect(udpreceiver, SIGNAL(readyRead()), this,SLOT(readPendingDatagrams()));
    qDebug()<<udpsender->localAddress()<<udpsender->localPort()<<senderPort;
    qDebug()<<udpreceiver->localAddress()<<udpreceiver->localPort()<<receiverPort;
}
MainWindow::~MainWindow(){ delete ui;}
void MainWindow::chatting_connected(){
    chatterState = 1;
    current_socket = chat_socket;
    connect(this->chat_socket,SIGNAL(readyRead()),this,SLOT(on_readychatting()));
    connect(this->chat_socket,SIGNAL(disconnected()),this,SLOT(chatting_dis()));
    ui->msg_list->addItem("connected!");
}
void MainWindow::readPendingDatagrams()
{
    while(udpreceiver->hasPendingDatagrams())
    {
        arr.resize(udpreceiver->pendingDatagramSize());
        udpreceiver->readDatagram(arr.data(),arr.size(),&host,&port);
        QDataStream readdst(&arr,QIODevice::ReadWrite);
        readdst>>sequencetemp>>dataarr;
        if(dataarr.size())      //dataarr非0，接受文件
        {
            sequenceSent = sequencetemp;
            QDataStream writedst(&arr,QIODevice::ReadWrite);
            arr.clear();
            if(sequenceSent == sequenceAccepted + 1)    //若收到的序号是递增的，则将数据写入文件，并返回递增的ack
            {
                sequenceAccepted++;
                file_rw->write(dataarr.data(),dataarr.size());
            }
            else if(sequencetemp == 0)
            {
                if(file_rw)
                {
                    ui->file_show->append("文件接收完毕！");
                    file_rw->close();
                    delete file_rw;
                    file_rw = 0;
                }
                sequenceAccepted  = 0;
            }
            //else
            //    ui->file_show->append(QString::number(sequencetemp));
            writedst<<sequenceAccepted;
            udpsender->writeDatagram(arr,chatterHost,chatter_udpport);  //Sends the datagram
        }
        else                //dataarr为0，上传文件
        {
            if(sequencetemp==sequenceAccepted + 1)
            {
                sequenceAccepted++;
                state = 0;
                timers[sequenceAccepted % winMax].stop();
                if(sequenceAccepted == end) {
                    if(winLen < winThreshold)
                        winLen *= 2;
                    else if(winLen < winMax)
                        winLen += 1;
                    end = end + winLen;
                    send();
                }
            }
            else if(sequencetemp == 0)
            {
                sequenceSent = 0;
                sequenceAccepted = 0;
                state = 0;
                if(file_rw) {
                    ui->file_show->append("文件发送完毕！");
                    file_rw->close();
                    delete file_rw;
                    file_rw = 0;
                    //tail = 0x7fffffffffffffff;
                   tail = 0;
                    endup = QDateTime::currentDateTime();
                    ui->file_show->append( "传输用时："+QString::number(start.secsTo(endup))+" 秒");
                }
            }
        }
    }
}
void MainWindow::on_resend()
{
    winThreshold /= 2;
    winLen = winThreshold + 3;
    reSend();
}
void MainWindow::reSend()       //存在问题
{
    for(int i=sequenceAccepted+1;i<=end; ++i)
        timers[i%winMax].stop();
    for(int i=sequenceAccepted + 1;i<=end  ;++i)
    {
        //if(i<=tail)
        if((!tail) ||  (i<=tail))
        {
            sequenceSent = i;
            udpsender->writeDatagram(arrbuf[sequenceSent % winMax],chatterHost,chatter_udpport);
            timers[sequenceSent%winMax].start(rtt);
        }
    }
}
void MainWindow::send()
{
    for(int i=sequenceAccepted + 1;i<=end ;++i)
    {
        sequenceSent = i;
        if(! file_rw->atEnd()) {
            QDataStream writedst(arrbuf+sequenceSent%winMax,QIODevice::ReadWrite);
            arrbuf[sequenceSent%winMax].clear();
            writedst<<sequenceSent;
            writedst<<file_rw->read(segLength);
            udpsender->writeDatagram(arrbuf[sequenceSent%winMax],chatterHost,chatter_udpport);
        }
        else {
            QDataStream writedst(arrbuf+sequenceSent%winMax,QIODevice::ReadWrite);
            arrbuf[sequenceSent%winMax].clear();
            writedst<<qint64(0)<<"end";
            udpsender->writeDatagram(arrbuf[sequenceSent%winMax].data(),
                    arrbuf[sequenceSent%winMax].size(), chatterHost,chatter_udpport);
            tail = sequenceSent;
            break;
        }
        timers[sequenceSent%winMax].start(rtt);
    }
}
void MainWindow::sendFile()
{
    file_rw = new QFile(file_full);
    file_rw->open(QIODevice::ReadOnly);
    sequenceSent=0;
    sequenceAccepted = 0;
    winThreshold = 32;
    winLen = 1;
    ackcount = 0;
    end =  winLen + sequenceAccepted;
    //t.start();
    send();
}
void MainWindow::receiveFile()
{
    QDir dir(QDir::currentPath());
    if (!dir.exists("files"))
    {
        dir.mkdir("files");
    }
    file_name = QString("%1/%2").arg("files", file_name);
    file_rw = new QFile (file_name);
    if (!file_rw->open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Unbuffered))
    {
        return;
    }
    sequenceAccepted = 0;
}
void MainWindow::chatting_dis(){
    chatterState = 0;
}
void MainWindow::chatted_connected()
{
    chatterState = 1;
    ui->msg_list->addItem("newconnection!");
    login* p = new login(chat_server);
    p->next = conn_users->next;
    conn_users->next = p;
    connect(p ,SIGNAL(newMessage(login*)),this,SLOT(on_readyread(login*)));
    current_socket = p->socket;
}
void MainWindow::on_readychatting()
{
    current_socket = chat_socket;
    chatterState = 1;
    handleMsg();
}
void MainWindow::on_readyread(login* sender)
{
    current_socket = sender->socket;
    handleMsg();
    ui->label_friend->setText(current_chatter);
    sender->account = current_chatter;
}
void MainWindow::handleMsg()        //处理收到的信息
{
    QByteArray arr;
    arr = current_socket->readAll();
    QDataStream dst(&arr,QIODevice::ReadWrite);
    QString head,my_account,chatter,str;
    dst>>head>>chatter;
    if(chatter.size())
    {
        current_chatter = chatter;
        if(head=="chatmsg")
        {
            dst>>my_account>>str;
            ui->label_friend->setText(current_chatter);
            ui->msg_list->addItem("["+current_chatter+"] "+str);
        }
        else if(head=="filepath")
        {
            dst>>file_name>>chatterHost>>chatter_udpport;
            ui->file_show->append("["+current_chatter+"] "+str);
            dialogSave();
        }
        else if(head=="filewanted")//文件名已收到，可发送文件
        {
            msg_file = 1;
            dst>>chatter_udpip>>chatter_udpport;
            chatterHost.setAddress(chatter_udpip);
            ui->file_show->append("开始发送文件！");
            start = QDateTime::currentDateTime();
            sendFile();
        }
        else if(head=="img")
        {
            qDebug()<<"img";
            int imgSize;
            QString imgName;
            dst>>imgName>>imgSize;
            disconnect(current_socket,SIGNAL(readyRead()),this,SLOT(on_readychatting()));
            arr.clear();
            QDataStream wdst(&arr,QIODevice::ReadWrite);
            wdst<<QString("accepted");
            sendmessage(arr,current_socket);
            QByteArray contentByteArray, subContentByteArray;
            while (imgSize > 0)
            {
                if (current_socket->waitForReadyRead())
                {
                    subContentByteArray = current_socket->readAll();
                    contentByteArray.append(subContentByteArray);
                    imgSize -= subContentByteArray.size();
                }
            }
            connect(current_socket,SIGNAL(readyRead()),this,SLOT(on_readychatting()));
            if (imgName.split('.').last() == "gif")
            {
                QDir dir(QDir::currentPath());
                if (!dir.exists("img"))
                {
                    dir.mkdir("img");
                }
                imgName = QString("%1/%2").arg("img", imgName);
                QFile imgFile(imgName);
                if (!imgFile.open(QIODevice::WriteOnly))
                {
                    return;
                }
                imgFile.write(contentByteArray);
                QLabel *gifLabel = new QLabel;
                QMovie *gif = new QMovie(imgName);
                gif->setScaledSize(QSize(200, 200));
                if (!gif->isValid())
                {
                    delete gifLabel;
                    return;
                }
                gifLabel->setMovie(gif);
                QListWidgetItem *item = new QListWidgetItem;
                item->setSizeHint(QSize(200, 200));
                ui->msg_list->addItem("["+current_chatter+"]");
                ui->msg_list->addItem(item);
                ui->msg_list->setItemWidget(item, gifLabel);
                gif->start();
            }
            else
            {
                QPixmap pixmap;
                pixmap.loadFromData(contentByteArray);
                QIcon img(pixmap);
                QListWidgetItem *item = new QListWidgetItem(img, "");
                ui->msg_list->addItem("["+current_chatter+"]");
                ui->msg_list->addItem(item);
            }
        }
    }
}
void MainWindow::dialogSave()
{
    QMessageBox box;
    box.question(this,"文件提醒","收到新文件："+file_name+" 是否保存？",
                          QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(box.Accepted)
    {
        arr.clear();
        QDataStream wdst(&arr,QIODevice::ReadWrite);
        wdst<<QString("filewanted")<<myaccount<<localip<<receiverPort;
        sendmessage(arr,current_socket);
        ui->file_show->append("准备接收文件………\n");
        receiveFile();
    }
}
void MainWindow::on_btn_send_clicked()
{
    if(current_chatter.size())
    {
        QString str=this->ui->text_send->toPlainText();
        if(str.size())
        {
            this->ui->text_send->clear();
            this->arr.clear();
            QDataStream dst(&arr,QIODevice::ReadWrite);
            if(msg_file)            //发送文本信息
            {
                dst<<QString("chatmsg") <<myaccount<<current_chatter<<str;
                this->ui->msg_list->addItem("["+myaccount+"] "+str);
            }
            else                    //发送文件
            {
                dst<<QString("filepath") <<myaccount<<file_name<<hostReceiver<<receiverPort;
                this->ui->file_show->append("["+myaccount+"] "+file_full);
                ui->file_show->append("等待对方确认接收文件………");
            }
            if(chatterState)        //判断对方是否在线
                sendmessage(arr,current_socket);
            else  sendmessage(arr);
        }
    }
}
void MainWindow::reconnect(){
    this->m_socket->connectToHost(serverip,2001,QTcpSocket::ReadWrite);
}
void MainWindow::connect_to_chatter(){
    this->chat_socket->connectToHost(chatter_ip,chatter_port,QTcpSocket::ReadWrite);
}
void MainWindow::on_connected(){
    conn_or_not = 1;
    connect(this->m_socket,SIGNAL(readyRead()),this,SLOT(on_readyread()));
}
void MainWindow::on_discon(){
    conn_or_not = 0;
    logout_succeed();
}
void MainWindow::on_list_friend_itemDoubleClicked(QListWidgetItem *item)
{
    current_chatter = item->text();
    ui->label_friend->setText(current_chatter);
    arr.clear();
    QDataStream dst(&arr,QIODevice::ReadWrite);
    dst<<QString("applyforip")<<myaccount<<current_chatter;
    sendmessage(arr);
}
void MainWindow::on_btn_file_clicked()
{
    fileDialog = new QFileDialog(this); //选择文件
    fileDialog->setWindowTitle(tr("选择文件")); //定义文件对话框标题
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog->setViewMode(QFileDialog::Detail); //设置视图模式
    ui->text_send->clear();
    if(fileDialog->exec()==QDialog::Accepted)
    {
        msg_file = 0;
        file_full = fileDialog->selectedFiles().at(0);
        ui->text_send->append("[文件] "+file_full);
        QFileInfo info = QFileInfo(file_full);
        file_name = info.fileName();
    }
    delete fileDialog;
}
void MainWindow::on_readyread()
{
    QByteArray arr=this->m_socket->readAll();
    QDataStream dst(&arr,QIODevice::ReadWrite);//重点
    QString head,head2;
    dst>>head;
    QString account;
    if(head=="reg")
    {
        dst>>head2>>account;
        if(account==this->reg_dialog->account)
        {
            if(head2=="ack")
            {
                reg_dialog->close();
                delete reg_dialog;
                m_socket->close();
                QMessageBox::about(this,"提示","注册成功！！！");
            }
            else if(head2=="fail")
                QMessageBox::about(this,"警告","注册失败，账号已存在！！！");
        }
    }
    else if(head=="login")
    {
        dst>>head2>>account;
        if(account==this->account)
        {
            if(head2=="ack")
            {
                login_succeed();
                QString off_or_not,msg,chatter;
                dst>>off_or_not;
                if(off_or_not=="offmsg")        //有离线消息
                {
                    qDebug()<<"离线";
                    while(1)
                    {
                        dst>>chatter>>msg;
                        if(chatter.size())
                        {
                            ui->msg_list->addItem("["+chatter+"] "+"(离线消息)"+msg);
                        }
                        else break;
                    }
                }
            }
            else if(head2=="fail")
                QMessageBox::about(this,"警告","登录失败，账号或密码错误！！！");
            else if(head2=="none")
                QMessageBox::about(this,"警告","登录失败，账号不存在！！！");
        }
    }
    else if(head=="find")
    {
        dst>>head2>>account;
        if(account==this->find_dialog->account)
        {
            if(head2=="ack")
            {
                find_dialog->close();
                delete find_dialog;
                m_socket->close();
                QMessageBox::about(this,"提示","找回成功，请牢记新密码！");
            }
            else if(head2=="fail")
                QMessageBox::about(this,"警告","找回失败，问题回答错误！！！");
            else if(head2=="wrong")
                QMessageBox::about(this,"警告","找回失败，密保问题错误！！！");
            else QMessageBox::about(this,"警告","找回失败，账号不存在！！！");
        }
    }
    else if(head=="friend")
    {
        allusers->destroy();
        user *p;
        int user_num;
        dst>>user_num;
        ui->list_friend->clear();
        for(int i=0;i<user_num;++i)
        {
            p = new user();
            dst>>p->account;
            p->next = allusers->next;
            allusers->next = p;
            ui->list_friend->addItem(p->account);
        }
    }
    else if(head=="getip")
    {
        chat_socket->close();//先断开，再连接，防止重复连接
        dst>>head2;
        if(head2=="friendonline")
        {
            dst>>chatter_ip>>chatter_port;
            chatterState = 1;
            login *p = conn_users->find(current_chatter);//不安全
            if(p )
            {
                if(p->inout)
                {
                    //QMessageBox::about(this,"x","chatted before");
                    current_socket = p->socket;
                    return;
                }
            }
            connect_to_chatter();
        }
        else if(head2=="friendoff")
        {
            chatterState = 0;
        }
    }
}
void MainWindow::on_btn_close_clicked(){ this->close();}

void MainWindow::sendimg(){
    QDir dir;
    dir.currentPath();
    if (!dir.exists("img"))
    {
        dir.mkdir("img");
    }
    dir.cd("img");
    QString imgPath = QFileDialog::getOpenFileName(this,"发送本地表情",
                                                   dir.currentPath() + "/img", "*.png;;*.jpg;;*.jpeg;;*.gif");
    if (imgPath == "")
    {
        return;
    }
    QFile img(imgPath);
    img.open(QIODevice::ReadOnly);
    if (!img.isOpen())
    {
        QMessageBox::about(this,"本地表情","获取资源失败");
        return;
    }
    int imgSize = img.size();
    QByteArray content = img.readAll();
    img.close();

    if(current_chatter.size() && chatterState)      //判断用户在线，发送请求
    {
        this->arr.clear();
        QDataStream dst(&arr,QIODevice::ReadWrite);
        dst<<QString("img")<<myaccount<<imgPath.split('/').last()<<imgSize;     //head,account,name,size
        current_socket->write(arr);
    }
    else
    {
        QMessageBox::about(this,"本地表情","未建立连接");
        return;
    }

    disconnect(current_socket,SIGNAL(readyRead()),this,SLOT(on_readychatting()));
    if (current_socket->waitForReadyRead())
        {
            qDebug()<<"Point2";

            QByteArray arr;
            arr = current_socket->readAll();
            QDataStream dst(&arr,QIODevice::ReadWrite);
            QString head;
            dst>>head;
            qDebug()<<head;
            if (head == "accepted")
            {
                current_socket->write(content);
            }
            else
            {
                QMessageBox::about(this,"本地表情","接收响应失败");
                connect(current_socket,SIGNAL(readyRead()),this,SLOT(on_readychatting()));
                return;
            }
        }
    qDebug()<<"Point1";
    connect(current_socket,SIGNAL(readyRead()),this,SLOT(on_readychatting()));

    QString imgName = imgPath.split('/').last();
    if (imgName.split('.').last() == "gif")
    {
        QLabel *gifLabel = new QLabel;
        QMovie *gif = new QMovie(imgPath);
        gif->setScaledSize(QSize(200, 200));
        if (!gif->isValid())
        {
            delete gifLabel;
            return;
        }
        gifLabel->setMovie(gif);
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(200, 200));
        ui->msg_list->addItem("["+myaccount+"]");
        ui->msg_list->addItem(item);
        ui->msg_list->setItemWidget(item, gifLabel);
        gif->start();
    }
    else
    {
        QPixmap pixmap;
        pixmap.loadFromData(content);
        QIcon img(pixmap);
        QListWidgetItem *item = new QListWidgetItem(img, "");
        ui->msg_list->addItem("["+myaccount+"]");
        ui->msg_list->addItem(item);
    }


}

void MainWindow::sendmessage(QByteArray &arr,QTcpSocket *chatter){
    chatter->write(arr);
}
void MainWindow::sendmessage(QByteArray &arr){      //对方离线，发送给服务器
    if(!conn_or_not)  reconnect();
    m_socket->write(arr);
}
void MainWindow::on_btn_login_clicked()
{
    account = ui->line_account->text();
    psw = ui->line_psw->text();
    myaccount = account;
    arr.clear();
    QDataStream dst(&arr,QIODevice::ReadWrite);
    dst<<QString("login") <<localip<<myport<<account<<psw;
    sendmessage(arr);
}
void MainWindow::login_succeed()
{
    ui->btn_send->show();
    ui->btn_off->show();
    ui->btn_file->show();
    ui->btn_img->show();
    ui->btn_login->hide();
    ui->btn_close->hide();

    ui->msg_list->show();

    ui->line_account->hide();
    ui->line_psw->hide();

    ui->menuBar->hide();
    ui->mainToolBar->hide();

    ui->label_account->hide();
    ui->label_psw->hide();
    ui->label_friend->show();
    ui->label_myname->show();
    ui->list_friend->show();
    ui->text_send->show();
    ui->msg_list->clear();
    ui->btn_getfriend->show();
    ui->label_myname->setText(myaccount);
    ui->file_show->show();
    ui->file_show->clear();
    ui->msg_list->addItem("myip: " + localip+"\nmy tcp port: "+QString::number(myport)+"\nmy udp port: "
                          +QString::number(receiverPort));
}
void MainWindow::logout_succeed()
{
    ui->btn_send->hide();
    ui->btn_off->hide();
    ui->btn_file->hide();
    ui->btn_img->hide();
    ui->btn_login->show();
    ui->btn_close->show();
    ui->msg_list->hide();
    ui->line_account->show();
    ui->line_psw->show();

    ui->menuBar->show();
    ui->mainToolBar->show();

    ui->label_account->show();
    ui->label_psw->show();
    ui->label_friend->hide();
    ui->label_myname->hide();

    ui->list_friend->hide();
    ui->text_send->hide();
    ui->line_account->clear();
    ui->line_psw->clear();
    ui->btn_getfriend->hide();
    ui->list_friend->clear();
    ui->label_friend->clear();
    ui->file_show->hide();
    current_chatter.clear();
    myaccount.clear();
}
void MainWindow::on_action_register_triggered()
{
    reg_dialog = new RegisterDialog;
    reg_dialog->show();
    connect(this->reg_dialog,SIGNAL(sendregmsg(QByteArray&)),
            this,SLOT(sendmessage(QByteArray&)));
}
void MainWindow::on_action_find_triggered()
{
    find_dialog = new findpswDialog;
    find_dialog->show();
    connect(this->find_dialog,SIGNAL(sendfindmsg(QByteArray&)),
            this,SLOT(sendmessage(QByteArray&)));//是否应该在别处连接
}
void MainWindow::on_btn_off_clicked()
{
    arr.clear();
    QDataStream dst(&arr,QIODevice::ReadWrite);
    dst<<QString("logout") <<myaccount;
    sendmessage(arr);
    m_socket->close();
    chat_socket->close();
    conn_users->destroy();
    logout_succeed();
}
void MainWindow::on_btn_getfriend_clicked()
{
    arr.clear();
    QDataStream dst(&arr,QIODevice::ReadWrite);
    dst<<QString("getfriend") <<myaccount;
    sendmessage(arr);
}
