#include "building.h"


Building::Building(){}

Building::Building(QString name)
{
    this->name = name;
}

QString Building::getName()
{
    return name;
}

void Building::setName(QString name)
{
    this->name = name;
}
