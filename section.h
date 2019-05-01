#ifndef SECTION_H
#define SECTION_H

#include<QString>

class Section
{
private:
    QString courseName;
    int sectionId;
    QString year;
    QString semester;
    QString startTime;
    QString endTime;
    QString bldgName;
    int roomNum;
    int profEid;

public:
    Section();
    Section(QString, int, QString, QString, QString, QString,
            QString, int, int);
    QString getCourseName();
    int getSectionId();
    QString getYear();
    QString getSemester();
    QString getStartTime();
    QString getEndTime();
    QString getBldgName();
    int getRoomNum();
    int getProfEid();
    void setCourseName(QString);
    void setSectionId(int);
    void setYear(QString);
    void setSemester(QString);
    void setStartTime(QString);
    void setEndTime(QString);
    void setBldgName(QString);
    void setRoomNum(int);
    void setProfEid(int);
};

#endif // SECTION_H
