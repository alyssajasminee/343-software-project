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
    Admin(int id, QString password);

    int getID();
    QString getPassword();

    void setID(int id);
    void setPassword(QString password);
};

#endif // ADMIN_H
