#include "user.h"

user::user()
{
    next = 0;
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
