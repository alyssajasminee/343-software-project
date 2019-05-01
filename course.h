#ifndef COURSE_H
#define COURSE_H

#include<QString>

class Course
{
private:
    QString majorName;
    QString courseName;
    int units;

public:
    Course();
    Course(QString, QString, int);
    QString getMajorName();
    QString getCourseName();
    int getUnits();
    void setMajorName(QString);
    void setCourseName(QString);
    void setUnits(int);
};

#endif // COURSE_H
