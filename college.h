#ifndef COLLEGE_H
#define COLLEGE_H

#include<QString>

class College
{
private:
    QString name;
    int deanEid;

public:
    College();
    College(QString, int);
    QString getName();
    int getDeanEid();
    void setName(QString);
    void setDeanEid(int);
};

#endif // COLLEGE_H
