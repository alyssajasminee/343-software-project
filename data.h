#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "database.h"
#include "student.h"
#include "college.h"

class Data
{
public:
    Data();
    //
    bool static superuserLogin(int, QString);

    //
    bool static adminLogin(int, QString);
    void static insertAdmin(QString);
    void static deleteAdmin(int);
    void static updateAdmin(int, QString);

    //
    QVector<Student> static selectStudents();
    Student static selectStudentById(int);
    void static insertStudent(QString, QString, QString, QString);
    void static deleteStudent(int);
    void static updateStudent(int, QString, QString, QString, QString);
    bool static studentLogin(int, QString);

    //
    bool static isEmployee(int);
    void static insertEmployee(QString, QString, QString, QString, float);

    //
    int static collegeCount();
    QVector<College> static selectColleges();
    void static insertCollege(QString, int);

    //
    void static insertDepartment(QString, QString, int);

};

#endif // DATA_H
