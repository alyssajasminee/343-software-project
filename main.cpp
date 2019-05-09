#include "mainwindow.h"
#include <QApplication>

#include "database.h"
#include "data.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QCoreApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    Database db;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir::currentPath();
    QString dbname = "/database/database.db";
    db.setDatabaseName(path + dbname);

    db.open();
    w.show();

    return a.exec();
}
