#include "college.h"

College::College(){}

College::College(QString name, int deanEid)
{
    this->name = name;
    this->deanEid = deanEid;
}

void College::setName(QString name)
{
    this->name = name;
}

void College::setDeanEid(int deanEid)
{
    this->deanEid = deanEid;
}

QString College::getName()
{
    return name;
}

int College::getDeanEid()
{
    return deanEid;
}
