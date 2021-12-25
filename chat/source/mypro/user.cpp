#include "user.h"

user::user()
{
    next = 0;
    inout = 0;
    user_port = 0;
    offmsg = 0;
}
user::~user()
{
}
user* user::finduser(QString &account)
{
    user *p=this->next;
    while(p )
    {
        if(p->account==account)
            return p;
        p = p->next;
    }
    return 0;
}
void user::destroy()
{
    user*p = this->next, *pp=p;
    while(pp)
    {
        pp=p->next;
        free(p);
        p = pp;
    }
    this->next = 0;
}
