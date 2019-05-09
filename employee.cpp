#include "employee.h"

Employee::Employee()
{
    this->eID = 0;
    this->firstName = "";
    this->middleInitial = "";
    this->lastName = "";
    this->title = "";
    this->salary = 0.0;
}

Employee::Employee(int eID, QString firstName, QString middleInitial, QString lastName, QString title, float salary) {
    this->eID = eID;
    this->firstName = firstName;
    this->middleInitial = middleInitial;
    this->lastName = lastName;
    this->title = title;
    this->salary = salary;
}

Employee::~Employee() {

}

int Employee::getEID() {
    return eID;
}

QString Employee::getFirstName() {
    return firstName;
}

QString Employee::getMiddleInitial() {
    return middleInitial;
}

QString Employee::getLastName() {
    return lastName;
}

QString Employee::getTitle() {
    return title;
}

float Employee::getSalary() {
    return salary;
}

void Employee::setEID(int eID) {
    this->eID = eID;
}

void Employee::setFirstName(QString firstName) {
    this->firstName = firstName;
}

void Employee::setMiddleInitial(QString middleInitial) {
    this->middleInitial = middleInitial;
}

void Employee::setLastName(QString lastName) {
    this->lastName = lastName;
}

void Employee::setTitle(QString title) {
    this->title = title;
}

void Employee::setSalary(float salary) {
    this->salary = salary;
}
