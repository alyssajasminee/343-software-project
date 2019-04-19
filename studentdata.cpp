#include "studentdata.h"

void StudentData::selectStudents()
{
    QString sql = "SELECT * FROM Student";

    QSqlQuery query;
    if(!query.exec(sql))
            qDebug()<<"Query failed"
                   <<query.lastError();
    while(query.next()){
        int id= query.value(0).toInt();
        QString fname = query.value(1).toString();

        qDebug()<<"Id = "<< id<<" Name = "<< fname;
    }
}

void StudentData::selectStudentById(int id)
{
    QString sql = "SELECT * FROM Student where id= (:id)";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.exec();

    if(query.first())
        qDebug()<<"Student found";
    else {
        qDebug()<<"Student not found";
    }
//    while(query.next()){
//        int id= query.value(0).toInt();
//        QString fname = query.value(1).toString();

//        qDebug()<<"Id = "<< id<<" Name = "<< fname;
//    }

}

int StudentData::insertStudent(Student)
{
    QString sql = "INSERT INTO Student (password, fname, mi, lname)"
                  "VALUES (;


    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.bindValue(":password", password);
    query.exec();

}

bool StudentData::authenticate(int id, QString password)
{
    QString sql = "SELECT * FROM Student "
                  "where id= (:id)"
                  "and password= (:password)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.bindValue(":password", password);
    query.exec();

    if(query.first())
        return true;

    return false;
}
