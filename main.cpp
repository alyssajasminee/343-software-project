#include "mainwindow.h"
#include <QApplication>

#include "database.h"
#include "studentdata.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Database db;
    bool login = StudentData::authenticate(1000, "pass");
    if(login)
        qDebug()<<"Login Success\n";
    else
        qDebug()<<"Login Failed\n";

    w.show();

    return a.exec();
}
