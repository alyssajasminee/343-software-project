#include "major.h"

Major::Major(){}

Major::Major(QString deptName, QString majorName)
{
    this->deptName = deptName;
    this->majorName = majorName;
}

void Major::setDeptName(QString deptName)
{
    this->deptName = deptName;
}

void Major::setMajorName(QString majorName)
{
    this->majorName = majorName;
}

QString Major::getDeptName()
{
    return deptName;
}

QString Major::getMajorName()
{
    return majorName;
}
