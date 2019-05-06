#include "course.h"

Course::Course(){};

Course::Course(QString majorName, QString courseName, int units)
{
    this->majorName = majorName;
    this->courseName = courseName;
    this->units = units;
}

QString Course::getMajorName()
{
    return majorName;
}

QString Course::getCourseName()
{
    return courseName;
}

int Course::getUnits()
{
    return units;
}

void Course::setMajorName(QString majorName)
{
    this->majorName = majorName;
}

void Course::setCourseName(QString courseName)
{
    this->courseName = courseName;
}

void Course::setUnits(int units)
{
    this->units = units;
}
