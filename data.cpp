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

int Data::insertAdmin(QString pass)
{
    QString sql = "INSERT INTO Admin(password)"
                  "VALUES (:password)";


    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.exec();

    int adminId = -1;
    if(query.numRowsAffected() > 0){
        QVariant var = query.lastInsertId();
        adminId = var.toInt();
    }

    return adminId;
}

bool Data::deleteAdmin(int id)
{
    QString sql = "DELETE FROM Admin where id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateAdmin(int id, QString pass)
{
    QString sql = "UPDATE Admin SET password= (:password)"
                         "WHERE id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.bindValue(":id", id);
    query.exec();

    return query.numRowsAffected() > 0;
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

QVector<Student> Data::selectStudents()
{
    QString sql = "SELECT * FROM Student";

    QSqlQuery query;
    query.exec(sql);

    QVector<Student> students;
    while(query.next()){
        int id= query.value(0).toInt();
        QString pass = query.value(1).toString();
        QString fname = query.value(2).toString();
        QString mi = query.value(3).toString();
        QString lname = query.value(4).toString();
        QString major = query.value(5).toString();

        Student s(id, pass, fname, mi, lname, major);
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
        QString major = query.value(5).toString();

        s.setId(id);
        s.setPass(pass);
        s.setFirstName(fname);
        s.setMiddleInitial(mi);
        s.setLastName(lname);
        s.setMajor(major);
    }

    return s;

}

int Data::insertStudent(
        QString pass, QString fname, QString mi, QString lname, QString major)
{
    QString sql = "INSERT INTO Student(password, fname, mi, lname, major)"
                  "VALUES (:password , :fname , :mi , :lname, :major)";


    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.bindValue(":fname", fname);
    query.bindValue(":mi", mi);
    query.bindValue(":lname", lname);
    query.bindValue(":major", major);
    query.exec();

    int studentId = -1;
    if(query.numRowsAffected() > 0){
        QVariant var = query.lastInsertId();
        studentId = var.toInt();
    }

    return studentId;
}

bool Data::deleteStudent(int id)
{
    QString sql = "DELETE FROM Student where id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", id);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateStudent(
        int id, QString pass, QString fname, QString mi, QString lname, QString major)
{
    QString sql = "UPDATE Student SET password= (:password),"
                  "fname = (:fname), mi= (:mi), lname = (:lname), major= (:major)"
                  "WHERE id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":password", pass);
    query.bindValue(":fname", fname);
    query.bindValue(":mi", mi);
    query.bindValue(":lname", lname);
    query.bindValue(":major", major);
    query.bindValue(":id", id);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateStudentMajor(int id, QString major)
{
    QString sql = "UPDATE Student SET major= (:major) "
                  "WHERE id= (:id)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":major", major);
    query.bindValue(":id", id);
    query.exec();

    return query.numRowsAffected() > 0;

}


bool Data::isEmployee(int eid)
{
    QString sql = "SELECT * FROM Employee "
                  "where eid= (:eid)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":eid", eid);
    query.exec();

    return query.first();
}

int Data::insertEmployee(
        QString fname, QString mi, QString lname, QString title, double salary)
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

    int id = -1;
    if(query.numRowsAffected() > 0){
        QVariant var = query.lastInsertId();
        id = var.toInt();
    }

    return id;
}

bool Data::deleteEmployee(int eid)
{
    QString sql = "DELETE FROM Employee where eid= (:eid)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":eid", eid);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateEmployee(
        int eid, QString fname, QString mi, QString lname, QString title, double salary)
{
    QString sql = "UPDATE Employee SET "
                  "fname = (:fname), mi= (:mi), lname = (:lname), "
                  "title= (:title), salary= (:salary)"
                  "WHERE eid= (:eid)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":fname", fname);
    query.bindValue(":mi", mi);
    query.bindValue(":lname", lname);
    query.bindValue(":title", title);
    query.bindValue(":salary", salary);
    query.bindValue(":eid", eid);
    query.exec();

    return query.numRowsAffected() > 0;

}


int Data::collegeCount()
{
    QString sql = "SELECT COUNT(*) FROM College";

    QSqlQuery query;
    query.exec(sql);
    query.first();

    return query.value(0).toInt();
}

QVector<College> Data::selectColleges()
{
    QString sql = "SELECT * FROM College "
                  "ORDER BY name";

    QSqlQuery query;
    query.exec(sql);

    QVector<College> colleges;
    while(query.next()){
        QString name = query.value(0).toString();
        int deanEid = query.value(1).toInt();

        College c(name, deanEid);
        colleges.append(c);
    }

    return colleges;
}

bool Data::insertCollege(QString name, int deanEid)
{
    QString sql = "INSERT INTO College(name, deanEId) "
                  "VALUES (:name, :deanEid)";

    QSqlQuery query;    
    query.prepare(sql);
    query.bindValue(":name", name);
    query.bindValue(":deanEid", deanEid);
    query.exec();

    return query.numRowsAffected() > 0;
}


int Data::deptCount(QString collegeName)
{
    QString sql = "SELECT COUNT(*) FROM Department "
                  "WHERE collegeName= (:collegeName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":collegeName", collegeName);
    query.exec();
    query.first();

    return query.value(0).toInt();

}

QVector<Department> Data::selectDepartments(QString collegeName)
{
    QString sql = "SELECT * FROM Department "
                  "WHERE collegeName= (:collegeName) "
                  "ORDER BY deptName";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":collegeName", collegeName);
    query.exec();

    QVector<Department> depts;
    while(query.next()){
        QString collegeName = query.value(0).toString();
        QString deptName = query.value(1).toString();
        int chairEid = query.value(2).toInt();

        Department d(collegeName, deptName, chairEid);
        depts.append(d);
    }

    return depts;

}

bool Data::insertDepartment(
        QString collegeName, QString deptName, int chairEid)
{
    QString sql = "INSERT INTO Department(collegeName, deptName, chairEid) "
                      "VALUES (:collegeName, :deptName, :chairEid)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":collegeName", collegeName);
    query.bindValue(":deptName", deptName);
    query.bindValue(":chairEid", chairEid);
    query.exec();

    return query.numRowsAffected() > 0;

}


int Data::majorCount(QString deptName)
{
    QString sql = "SELECT COUNT(*) FROM Majors "
                  "WHERE deptName= (:deptName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":deptName", deptName);
    query.exec();
    query.first();

    return query.value(0).toInt();

}

QVector<Major> Data::selectMajors(QString deptName)
{
    QString sql = "SELECT * FROM Majors "
                  "WHERE deptName= (:deptName) "
                  "ORDER BY majorName";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":deptName", deptName);
    query.exec();

    QVector<Major> majors;
    while(query.next()){
        QString deptName = query.value(0).toString();
        QString majorName = query.value(1).toString();

        Major m(deptName, majorName);
        majors.append(m);
    }

    return majors;

}

bool Data::insertMajor(QString deptName, QString majorName)
{
    QString sql = "INSERT INTO Majors(deptName, majorName) "
                      "VALUES (:deptName, :majorName)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":deptName", deptName);
    query.bindValue(":majorName", majorName);
    query.exec();

    return query.numRowsAffected() > 0;

}
