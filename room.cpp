#include "room.h"

Room::Room(){}

Room::Room(QString bldgName, int roomNum, int capacity)
{
    this->bldgName = bldgName;
    this->roomNum = roomNum;
    this->capacity = capacity;
}

QString Room::getBldgName()
{
    return bldgName;
}

int Room::getRoomNum()
{
    return roomNum;
}

int Room::getCapacity()
{
    return capacity;
}

void Room::setBldgName(QString bldgName)
{
    this->bldgName = bldgName;
}

void Room::setRoomNum(int roomNum)
{
    this->roomNum = roomNum;
}

void Room::setCapacity(int capacity)
{
    this->capacity = capacity;
}
