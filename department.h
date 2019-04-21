#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<QString>

class Department
{
private:
    QString name;
    QString chair;

public:
    Department();
    Department(QString, QString);
    void setName(QString);
    void setChair(QString);
    QString getName();
    QString getChair();
};

#endif // DEPARTMENT_H
