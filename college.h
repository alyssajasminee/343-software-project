#ifndef COLLEGE_H
#define COLLEGE_H

#include<QString>

class College
{
private:
    QString name;
    QString dean;

public:
    College();
    College(QString, QString);
    QString getName();
    QString getDean();
    void setName(QString);
    void setDean(QString);
};

#endif // COLLEGE_H
