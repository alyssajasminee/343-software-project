#include "section.h"

Section::Section(){}

Section::Section(QString courseName, int sectionId, QString year,
                 QString semester, QString startTime, QString endTime,
                 QString bldgName, int roomNum, int profEid)
{
    this->courseName = courseName;
    this->sectionId = sectionId;
    this->year = year;
    this->semester = semester;
    this->startTime = startTime;
    this->endTime = endTime;
    this->bldgName = bldgName;
    this->roomNum = roomNum;
    this->profEid = profEid;
}

QString Section::getCourseName()
{
    return courseName;
}

int Section::getSectionId()
{
    return sectionId;
}

QString Section::getYear()
{
    return year;
}

QString Section::getSemester()
{
    return semester;
}

QString Section::getStartTime()
{
    return startTime;
}

QString Section::getEndTime()
{
    return endTime;
}

QString Section::getBldgName()
{
    return bldgName;
}

int Section::getRoomNum()
{
    return roomNum;
}

int Section::getProfEid()
{
    return profEid;
}

void Section::setCourseName(QString courseName)
{
    this->courseName = courseName;
}

void Section::setSectionId(int sectionId)
{
    this->sectionId = sectionId;
}

void Section::setYear(QString year)
{
    this->year = year;
}

void Section::setSemester(QString  semester)
{
    this->semester = semester;
}

void Section::setStartTime(QString startTime)
{
    this->startTime = startTime;
}

void Section::setEndTime(QString endTime)
{
    this->endTime = endTime;
}

void Section::setBldgName(QString bldgName)
{
    this->bldgName = bldgName;
}

void Section::setRoomNum(int roomNum)
{
    this->roomNum = roomNum;
}

void Section::setProfEid(int profEid)
{
    this->profEid = profEid;
}


