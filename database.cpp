#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QCoreApplication::applicationDirPath();
    QString dbname = "/database.db";
    db.setDatabaseName(path + dbname);

    db.open();
}
