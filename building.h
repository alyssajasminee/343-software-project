#ifndef BUILDING_H
#define BUILDING_H

#include<QString>

class Building
{
private:
    QString name;

public:
    Building();
    Building(QString);
    QString getName();
    void setName(QString);
};

#endif // BUILDING_H
