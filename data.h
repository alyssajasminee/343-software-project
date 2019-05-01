#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "database.h"
#include "student.h"
#include "college.h"
#include "department.h"
#include "major.h"
#include "course.h"

class Data
{
public:
    Data();
    //
    bool static superuserLogin(int, QString);

    //
    bool static adminLogin(int, QString);
    int static insertAdmin(QString);
    bool static deleteAdmin(int);
    bool static updateAdmin(int, QString);

    //
    bool static studentLogin(int, QString);
    QVector<Student> static selectStudents();
    Student static selectStudentById(int);
    int static insertStudent(QString, QString, QString, QString, QString);
    bool static deleteStudent(int);
    bool static updateStudent(int, QString, QString, QString, QString, QString);
    bool static updateStudentMajor(int, QString);

    //
    bool static isEmployee(int);
    int static insertEmployee(QString, QString, QString, QString, double);
    bool static deleteEmployee(int);
    bool static updateEmployee(int, QString, QString, QString, QString, double);

    //
    int static collegeCount();
    QVector<College> static selectColleges();
    bool static insertCollege(QString, int);

    //
    int static deptCount(QString);
    QVector<Department> static selectDepartments(QString);
    bool static insertDepartment(QString, QString, int);

    //
    int static majorCount(QString);
    QVector<Major> static selectMajors(QString);
    bool static insertMajor(QString, QString);

    //
    int static courseCount(QString);
    QVector<Course> static selectCourses(QString);


};

#endif // DATA_H
