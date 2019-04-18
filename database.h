#ifndef DATABASE_H
#define DATABASE_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QCoreApplication>

class Database
{
private:
    QSqlDatabase db;

public:
    Database();

};


#endif // DATABASE_H
