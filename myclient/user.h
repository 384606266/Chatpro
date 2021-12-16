#ifndef USER_H
#define USER_H
#include <QString>

class user
{
public:
    user();
    ~user();
    QString account;
    class user* next;
    void destroy();
};

#endif // USER_H
