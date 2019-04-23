#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include<QString>

class Department
{
private:
    QString collegeName;
    QString deptName;
    int chairEid;

public:
    Department();
    Department(QString, QString, int);
    void setCollegeName(QString);
    void setDeptName(QString);
    void setChairEid(int);
    QString getCollegeName();
    QString getDeptName();
    int getChairEid();
};

#endif // DEPARTMENT_H
