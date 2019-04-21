#include "college.h"

College::College(){}

College::College(QString name, QString dean)
{
    this->name = name;
    this->dean = dean;
}

void College::setName(QString name)
{
    this->name = name;
}

void College::setDean(QString dean)
{
    this->dean = dean;
}

QString College::getName()
{
    return name;
}

QString College::getDean()
{
    return dean;
}
