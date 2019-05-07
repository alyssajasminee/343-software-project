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
    public:
        Database();
        ~Database();
        QSqlDatabase db;
        static Database* getInstance();

    private:
        static bool created;
        static Database* globalBCInstance;
};


#endif // DATABASE_H
