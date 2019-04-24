#ifndef ADMIN_H
#define ADMIN_H

#include<QString>

class Admin
{
private:
    int id;
    QString password;

public:
    Admin();
    int getId();
    QString getPass();

};

#endif // ADMIN_H
