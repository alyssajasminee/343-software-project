#include "student.h"

Student::Student(){}

Student::Student(
        int id, QString pass, QString fname, QString mi, QString lname, QString major)
{
    this->id = id;
    this->password = pass;
    this->fname = fname;
    this->mi = mi;
    this->lname = lname;
    this->major = major;
}

int Student::getId()
{
    return id;
}

QString Student::getPass()
{
    return password;
}

QString Student::getFirstName()
{
    return fname;
}

QString Student::getMiddleInitial()
{
    return mi;
}

QString Student::getLastName()
{
    return lname;
}

QString Student::getMajor()
{
    return major;
}

void Student::setId(int id)
{
    this->id = id;
}

void Student::setPass(QString pass)
{
    this->password = pass;
}

void Student::setFirstName(QString fname)
{
    this->fname = fname;
}

void Student::setMiddleInitial(QString mi)
{
    this->mi = mi;
}

void Student::setLastName(QString lname)
{
    this->lname = lname;
}

void Student::setMajor(QString major)
{
    this->major = major;
}
