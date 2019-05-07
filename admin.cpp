#include "admin.h"

Admin::Admin(){}

Admin::Admin(int id, QString password) {
    this->id = id;
    this->password = password;
}

int Admin::getID() {
    return id;
}

QString Admin::getPassword() {
    return password;
}

void Admin::setID(int id) {
    this->id = id;
}

void Admin::setPassword(QString password) {
    this->password = password;
}
