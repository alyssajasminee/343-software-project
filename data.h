#ifndef DATA_H
#define DATA_H

#include <QVector>
#include "database.h"
#include "admin.h"
#include "student.h"
#include "employee.h"
#include "college.h"
#include "department.h"
#include "major.h"
#include "course.h"
#include "section.h"
#include "building.h"
#include "room.h"

class Data
{
public:
    Data();
    ~Data();
    //
    bool static superuserLogin(int, QString);

    //
    bool static adminLogin(int, QString);
    QVector<Admin> static selectAdmins();
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
    QVector<Employee> static selectEmployees();
    int static insertEmployee(QString, QString, QString, QString, double);
    bool static deleteEmployee(int);
    bool static updateEmployee(int, QString, QString, QString, QString, double);

    //
    QVector<int> static selectProfessors();

    //
    int static collegeCount();
    QVector<College> static selectColleges();
    bool static insertCollege(QString, int);
    bool static deleteCollege(QString);
    bool static updateCollege(QString, int, QString);

    //
    int static deptCount(QString);
    QVector<Department> static selectDepartments(QString);
    bool static insertDepartment(QString, QString, int);
    bool static deleteDepartment(QString);
    bool static updateDepartment(QString, QString, int, QString);

    //
    int static majorCount(QString);
    QVector<Major> static selectMajors(QString);
    bool static insertMajor(QString, QString);
    bool static deleteMajor(QString);
    bool static updateMajor(QString, QString, QString);

    //
    int static courseCount(QString);
    QVector<Course> static selectCourses(QString);
    Course static selectCourseByName(QString);
    bool static insertCourse(QString, QString, int);
    bool static deleteCourse(QString);
    bool static updateCourse(QString, QString, int, QString);

    //
    QVector<Section> static selectSections(QString, QString, QString);
    QVector<Section> static selectAllSections(QString);
    Section static selectSectionById(int);
    bool static insertSection(QString, QString, QString, QString, QString, QString, int, int);
    bool static deleteSection(int);
    bool static updateSection(QString, int, QString, QString, QString, QString, QString, int, int, int);

    //
    QVector<Building> static selectBuidings();
    bool static insertBuilding(QString);
    bool static deleteBuilding(QString);
    bool static updateBuilding(QString, QString);

    //
    QVector<Room> static selectRoomsByBuilding(QString);
    bool static insertRoom(QString, int, int);
    bool static deleteRoom(QString, int);
    bool static updateRoom(QString, int, int, QString, int);

    //
    bool static isRegistered(int, QString, QString);
    bool static insertRegister(int, QString, QString);

    //
    bool static isTuitionPaid(int, QString, QString);
    bool static insertTuition(int, QString, QString);

    //
    QVector<int> static selectStudentSections(int, QString, QString);
    bool static insertStudentSections(int, int, QString, QString);
    bool static deleteStudentSection(int, int, QString, QString);
    bool static insertStudentGrade(int, int, QString, QString, QString);

    //
    QVector<int> static selectProfessorSections(int, QString, QString);
    bool static insertProfessorSection(int, int, QString, QString);

    //
    QVector<QString> static selectPreReqs(QString);
    QVector<QString> static selectTranscript(int);
    private:
        Database *database;
};

#endif // DATA_H
