#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
private:
    int id;
    QString password;
    QString fname;
    QString mi;
    QString lname;
    QString major;


public:
    Student();
    Student(int, QString, QString, QString, QString, QString);
    int getId();
    QString getPass();
    QString getFirstName();
    QString getMiddleInitial();
    QString getLastName();
    QString getMajor();
    void setId(int);
    void setPass(QString);
    void setFirstName(QString);
    void setMiddleInitial(QString);
    void setLastName(QString);
    void setMajor(QString);
};

#endif // STUDENT_H
