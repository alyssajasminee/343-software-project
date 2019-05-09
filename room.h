#ifndef ROOM_H
#define ROOM_H

#include<QString>

class Room
{
private:
    QString bldgName;
    int roomNum;
    int capacity;

public:
    Room();
    Room(QString, int, int);
    QString getBldgName();
    int getRoomNum();
    int getCapacity();
    void setBldgName(QString);
    void setRoomNum(int);
    void setCapacity(int);
};

#endif // ROOM_H
