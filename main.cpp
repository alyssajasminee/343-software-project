#include "mainwindow.h"
#include <QApplication>

#include "database.h"
#include "data.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Database db;



    w.show();

    return a.exec();
}
