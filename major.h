#ifndef MAJOR_H
#define MAJOR_H

#include<QString>

class Major
{
private:
    QString deptName;
    QString majorName;

public:
    Major();
    Major(QString, QString);
    void setDeptName(QString);
    void setMajorName(QString);
    QString getDeptName();
    QString getMajorName();
};

#endif // MAJOR_H
