#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include "database.h"

class StudentData
{
public:
    StudentData();
    void static selectStudents();
    void static selectStudentById(int);
    bool static authenticate(int, QString);

};

#endif // STUDENTDATA_H
