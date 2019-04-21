#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir::currentPath();
    QString dbname = "/database/database.db";
    db.setDatabaseName(path + dbname);

    db.open();
    QSqlQuery query;


}
