#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "QString"

class Employee
{
public:
    Employee();
    Employee(int eID, QString firstName, QString middleInitial, QString lastName, QString title, float salary);
    ~Employee();

    int getEID();
    QString getFirstName();
    QString getMiddleInitial();
    QString getLastName();
    QString getTitle();
    float getSalary();

    void setEID(int eID);
    void setFirstName(QString firstName);
    void setMiddleInitial(QString middleInitial);
    void setLastName(QString lastName);
    void setTitle(QString title);
    void setSalary(float salary);

private:
    int eID;
    QString firstName;
    QString middleInitial;
    QString lastName;
    QString title;
    float salary;
};

#endif // EMPLOYEE_H
