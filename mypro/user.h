#ifndef USER_H
#define USER_H
#include <QString>
#include <QTcpSocket>
#include <QObject>
class user:public QObject
{
    Q_OBJECT
public:
    user();
    ~user();
    QString ip;
    QString account, psw, question, answer;
    class user* next;
    int inout,offmsg;
    quint16 user_port;
    user* finduser(QString &account);
    void destroy();
};

#endif // USER_H
