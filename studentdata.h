#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include "database.h"
#include "student.h"

class StudentData
{
public:
    StudentData();
    void static selectStudents();
    void static selectStudentById(int);
    int static insertStudent(Student);
    bool static authenticate(int, QString);

};

#endif // STUDENTDATA_H
