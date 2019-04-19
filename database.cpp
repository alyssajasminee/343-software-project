#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QCoreApplication::applicationDirPath();
    QString dbname = "/database.db";
    db.setDatabaseName(path + dbname);

    db.open();
    QSqlQuery query;

    query.exec("create table student "
              "(studentID integer   NOT NULL, "
              "password varchar(20), "
              "firstname varchar(20), "
              "lastname varchar(30), "
              "age integer,"
               "CONSTRAINT  pk_student PRIMARY KEY(studentID));");

    query.exec("create table transcript "
              "(studentID integer   NOT NULL, "
              "courseName varchar(30), "
              "grade varchar(1));");

    query.exec("create table studentSchedule "
              "(studentID integer   NOT NULL, "
              "courseName varchar(30), "
              "sectionNumber integer, "
               "roomNumber integer);");

    query.exec("create table room "
              "(roomNumber integer   NOT NULL, "
              "buildingName varchar(30), "
              "capacity integer, "
               "CONSTRAINT  pk_room PRIMARY KEY(roomNumber, buildingName));");
    query.exec("create table section "
              "(sectionNumber integer   NOT NULL, "
              "courseName varchar(30), "
              "enrolledStudents integer, "
               "roomNumber integer,"
               "CONSTRAINT  pk_section PRIMARY KEY(courseName, sectionNumber));");

    query.exec("create table course "
              "(courseName varchar(30)   NOT NULL, "
              "majorName varchar(30)"
               "CONSTRAINT  pk_course PRIMARY KEY(courseName));");

    query.exec("create table major "
              "(department   varchar(40) NOT NULL, "
              "majorName varchar(30), "
              "grade varchar(1));");

    query.exec("create table admin "
              "(userName   varchar(40) NOT NULL, "
              "password varchar(30) NOT NULL);");

    query.exec("ALTER TABLE transcript"
                "ADD CONSTRAINT student_ID_fk"
                "FOREIGN KEY(studentID)"
                "REFERENCES student(studentID);");

}
