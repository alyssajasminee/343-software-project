#include "department.h"

Department::Department(
        QString collegeName, QString deptName, int chairEid)
{
    this->collegeName = collegeName;
    this->deptName = deptName;
    this->chairEid = chairEid;
}

void Department::setCollegeName(QString name)
{
    collegeName = name;
}

void Department::setDeptName(QString name)
{
    deptName = name;
}

void Department::setChairEid(int eid)
{
    chairEid = eid;
}

QString Department::getCollegeName()
{
    return collegeName;
}

QString Department::getDeptName()
{
    return deptName;
}

int Department::getChairEid()
{
    return chairEid;
}
