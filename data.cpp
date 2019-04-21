#include "data.h"

bool Data::superuserLogin(int id, QString password)
{
    QString sql = "SELECT * FROM SuperUser "
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


bool Data::adminLogin(int id, QString password)
{
    QString sql = "SELECT * FROM Admin "
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

void Data::insertAdmin(QString pass)
{
    QString sql = "INSERT INTO Admin(password)"
                  "VALUES (:password)";


    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.exec();

    if(query.numRowsAffected() > 0){
        QVariant var = query.lastInsertId();
        int rowid = var.toInt();
        qDebug()<<"Admin ID = "<< rowid;
    }

}

void Data::deleteAdmin(int id)
{
    QString sql = "DELETE FROM Admin where id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.exec();
}

void Data::updateAdmin(int id, QString pass)
{
    QString sql = "UPDATE Admin SET password= (:pass)"
                         "WHERE id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.bindValue(":id", id);
    query.exec();
}


QVector<Student> Data::selectStudents()
{
    QString sql = "SELECT * FROM Student";

    QSqlQuery query;
    if(!query.exec(sql)){
            qDebug()<<"Query failed"
                   <<query.lastError();
    }

    QVector<Student> students;
    while(query.next()){
        int id= query.value(0).toInt();
        QString pass = query.value(1).toString();
        QString fname = query.value(2).toString();
        QString mi = query.value(3).toString();
        QString lname = query.value(4).toString();

        Student s(id, pass, fname, mi, lname);
        students.append(s);
    }

    return students;
}

Student Data::selectStudentById(int id)
{
    QString sql = "SELECT * FROM Student where id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.exec();

    Student s;
    if(query.first()){
        int id= query.value(0).toInt();
        QString pass = query.value(1).toString();
        QString fname = query.value(2).toString();
        QString mi = query.value(3).toString();
        QString lname = query.value(4).toString();

        s.setId(id);
        s.setPass(pass);
        s.setFirstName(fname);
        s.setMiddleInitial(mi);
        s.setLastName(lname);
    }

    return s;

}

void Data::insertStudent(
        QString pass, QString fname, QString mi, QString lname)
{
    QString sql = "INSERT INTO Student(id, password, fname, mi, lname)"
                  "VALUES (NULL, :password , :fname , :mi , :lname)";


    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.bindValue(":fname", fname);
    query.bindValue(":mi", mi);
    query.bindValue(":lname", lname);
    query.exec();

    if(query.numRowsAffected() > 0){
        QVariant var = query.lastInsertId();
        int rowid = var.toInt();
        qDebug()<<"Student ID = "<< rowid;
    }

}

bool Data::studentLogin(int id, QString password)
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

void Data::deleteStudent(int id)
{
    QString sql = "DELETE FROM Student where id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.exec();
}

void Data::updateStudent(
        int id, QString pass, QString fname, QString mi, QString lname)
{
    QString sql = "UPDATE Student SET password= (:pass),"
                  "fname = (:fname), mi= (:mi), lname = (:lname)"
                  "WHERE id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.bindValue(":fname", fname);
    query.bindValue(":mi", mi);
    query.bindValue(":lname", lname);
    query.bindValue(":id", id);
    query.exec();
}


bool Data::isEmployee(int eid)
{
    QString sql = "SELECT * FROM Employee "
                  "where eid= (:eid)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":eid", eid);
    query.exec();

    if(query.first())
        return true;

    return false;

}

void Data::insertEmployee(
        QString fname, QString mi, QString lname, QString title, float salary)
{
    QString sql = "INSERT INTO Employee(fname, mi, lname, title, salary)"
                  "VALUES (:fname , :mi , :lname, :title, :salary)";


    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":fname", fname);
    query.bindValue(":mi", mi);
    query.bindValue(":lname", lname);
    query.bindValue(":title", title);
    query.bindValue(":salary", salary);
    query.exec();

    if(query.numRowsAffected() > 0){
        QVariant var = query.lastInsertId();
        int rowid = var.toInt();
        qDebug()<<"Employee ID = "<< rowid;
    }
}


int Data::collegeCount()
{
    QString sql;
    QSqlQuery query;

    sql = "SELECT COUNT(*) FROM College";
    query.exec(sql);
    query.first();

    return query.value(0).toInt();
}

QVector<College> Data::selectColleges()
{
    QString sql = "SELECT * FROM College "
                  "ORDER BY name";

    QSqlQuery query;
    if(!query.exec(sql)){
            qDebug()<<"Query failed"
                   <<query.lastError();
    }

    QVector<College> colleges;
    while(query.next()){
        QString name = query.value(0).toString();
        QString dean = query.value(1).toString();

        College c(name, dean);
        colleges.append(c);
    }

    return colleges;
}

void Data::insertCollege(QString name, int deanEid)
{
    QString sql;
    QSqlQuery query;

    sql = "INSERT INTO College(name, dean) "
          "VALUES (:name, :dean)";

    query.prepare(sql);
    query.bindValue(":name", name);
    query.bindValue(":dean", deanEid);
    query.exec();


    qDebug()<<"ERROR = "<<query.lastError()
           <<"NUMBER = "<<query.lastError().nativeErrorCode();
}


void Data::insertDepartment(
        QString college, QString dept, int chairEid)
{
    QString sql;
    QSqlQuery query;

    sql = "INSERT INTO Department(college, dept, chair) "
          "VALUES (:college, :dept, :chair)";

    query.prepare(sql);
    query.bindValue(":name", college);
    query.bindValue(":dean", dept);
    query.bindValue(":chair", chairEid);
    query.exec();

}

