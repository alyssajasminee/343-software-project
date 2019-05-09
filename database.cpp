#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir::currentPath();
    QString dbname = "/database/database.db";
    db.setDatabaseName(path + dbname);

    db.open();
    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;");
}

Database::~Database()
{
    created = false;
}

bool Database::created = false;

Database* Database::globalBCInstance = NULL;

Database* Database::getInstance()
{
    if (!created)
    {
        globalBCInstance = new Database();
        created = true;
        return globalBCInstance;
    }
    else
    {
        return globalBCInstance;
    }
}
