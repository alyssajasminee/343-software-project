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


QVector<int> Data::selectProfessors()
{
    QString sql = "SELECT eid FROM Employee "
                  "WHERE title= (:title)";

    QString title = "professor";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":title", title);
    query.exec();

    QVector<int> profEids;
    while(query.next()){
        int id= query.value(0).toInt();

        profEids.append(id);
    }

    return profEids;
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

bool Data::deleteCollege(QString name)
{
    QString sql = "DELETE FROM College where name= (:name)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":name", name);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateCollege(
        QString name, int deanEid, QString curName)
{
    QString sql = "UPDATE College SET "
                  "name= (:name), deanEid= (:deanEid) "
                  "WHERE name= (:curName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":name", name);
    query.bindValue(":deanEid", deanEid);
    query.bindValue(":curName", curName);
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

bool Data::deleteDepartment(QString deptName)
{
    QString sql = "DELETE FROM Department where deptName= (:deptName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":deptName", deptName);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateDepartment(
        QString collegeName, QString deptName, int chairEid,
        QString curDeptName)
{
    QString sql = "UPDATE Department SET "
                  "collegeName = (:collegeName), deptName= (:deptName), "
                  "chairEid= (:chairEid) "
                  "WHERE deptName= (:curDeptName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":collegeName", collegeName);
    query.bindValue(":deptName", deptName);
    query.bindValue(":chairEid", chairEid);
    query.bindValue(":curDeptName", curDeptName);
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

bool Data::deleteMajor(QString majorName)
{
    QString sql = "DELETE FROM Majors where majorName= (:majorName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":majorName", majorName);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateMajor(
        QString deptName, QString majorName, QString curMajorName)
{
    QString sql = "UPDATE Majors SET "
                  "deptName= (deptName), majorName= (:majorName) "
                  "WHERE majorName= (:curMajorName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":deptName", deptName);
    query.bindValue(":majorName", majorName);
    query.bindValue(":curMajorName", curMajorName);
    query.exec();

    return query.numRowsAffected() > 0;
}


int Data::courseCount(QString majorName)
{
    QString sql = "SELECT COUNT(*) FROM Course "
                  "WHERE majorName= (:majorName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":majorName", majorName);
    query.exec();
    query.first();

    return query.value(0).toInt();

}

QVector<Course> Data::selectCourses(QString majorName)
{
    QString sql = "SELECT * FROM Course "
                  "WHERE majorName= (:majorName) "
                  "ORDER BY courseName";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":majorName", majorName);
    query.exec();

    QVector<Course> courses;
    while(query.next()){
        QString majorName = query.value(0).toString();
        QString courseName = query.value(1).toString();
        int units = query.value(2).toInt();

        Course c(majorName, courseName, units);
        courses.append(c);
    }

    return courses;
}

bool Data::insertCourse(
        QString majorName, QString courseName, int units)
{
    QString sql = "INSERT INTO Course(majorName, courseName, units) "
                      "VALUES (:majorName, :courseName, :units)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":majorName", majorName);
    query.bindValue(":courseName", courseName);
    query.bindValue(":units", units);
    query.exec();

    return query.numRowsAffected() > 0;

}

bool Data::deleteCourse(QString courseName)
{
    QString sql = "DELETE FROM Course where courseName= (:courseName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":courseName", courseName);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data:: updateCourse(
        QString majorName, QString courseName, int units,
        QString curCourseName)
{
    QString sql = "UPDATE Department SET "
                  "majorName = (:majorName), courseName= (:courseName), "
                  "units= (:units) "
                  "WHERE courseName= (:curCourseName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":majorName", majorName);
    query.bindValue(":courseName", courseName);
    query.bindValue(":units", units);
    query.bindValue(":curCourseName", curCourseName);
    query.exec();

    return query.numRowsAffected() > 0;
}


QVector<Section> Data::selectSections(
        QString courseName, QString year, QString semester)
{
    QString sql = "SELECT * FROM Sections "
                  "WHERE courseName= (:courseName) "
                  "AND year= (:year) "
                  "AND semester= (:semester)"
                  "ORDER BY sectionId";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":courseName", courseName);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.exec();

    QVector<Section> sections;
    while(query.next()){
        QString courseName = query.value(0).toString();
        int sectionId = query.value(1).toInt();
        QString year = query.value(2).toString();
        QString semester = query.value(3).toString();
        QString startTime = query.value(4).toString();
        QString endTime = query.value(5).toString();
        QString bldgName = query.value(6).toString();
        int roomNum = query.value(7).toInt();
        int profEid = query.value(8).toInt();

        Section s(courseName, sectionId, year, semester,
                  startTime, endTime, bldgName, roomNum, profEid);
        sections.append(s);
    }

    return sections;

}

Section Data::selectSectionById(int sectionId)
{
    QString sql = "SELECT * FROM Sections "
                  "WHERE sectionId= (:sectionId) ";


    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":sectionId", sectionId);
    query.exec();

    Section s;
    while(query.next()){
        QString courseName = query.value(0).toString();
        int sectionId = query.value(1).toInt();
        QString year = query.value(2).toString();
        QString semester = query.value(3).toString();
        QString startTime = query.value(4).toString();
        QString endTime = query.value(5).toString();
        QString bldgName = query.value(6).toString();
        int roomNum = query.value(7).toInt();
        int profEid = query.value(8).toInt();

        Section s(courseName, sectionId, year, semester,
                  startTime, endTime, bldgName, roomNum, profEid);
    }

    return s;
}

bool Data::insertSection(
        QString courseName, QString year,
        QString semester, QString startTime, QString endTime,
        QString bldgName, int roomNum, int profEid)
{
    QString sql = "INSERT INTO Sections(courseName, year, "
                  "semester, startTime, endTime, bldgName, "
                  "roomNum, profEid) "
                      "VALUES (:courseName, :year, "
                  ":semester, :startTime, :endTime, :bldgName, "
                  ":roomNum, :profEid)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":courseName", courseName);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);
    query.bindValue(":bldgName", bldgName);
    query.bindValue(":roomNum", roomNum);
    query.bindValue(":profEid", profEid);

    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::deleteSection(int sectionId)
{
    QString sql = "DELETE FROM Sections where sectionId= (:sectionId)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":sectionId", sectionId);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateSection(
        QString courseName, int sectionId, QString year,
        QString semester, QString startTime, QString endTime,
        QString bldgName, int roomNum, int profEid,
        int curSectionId)
{
    QString sql = "UPDATE Sections SET "
                  "courseName = (:courseName), sectionId= (:sectionId), "
                  "year = (:year), semester = (:semester), "
                  "startTime = (:startTime), endTime= (:endTime), "
                  "bldgName = (:bldgName), roomNum= (:roomNum), "
                  "profEid= (:profEid) "
                  "WHERE sectionId= (:curSectionId)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":courseName", courseName);
    query.bindValue(":sectionId", sectionId);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);
    query.bindValue(":bldgName", bldgName);
    query.bindValue(":roomNum", roomNum);
    query.bindValue(":profEid", profEid);
    query.bindValue(":curSectionId", curSectionId);
    query.exec();

    return query.numRowsAffected() > 0;
}


QVector<Building> Data::selectBuidings()
{
    QString sql = "SELECT * FROM Building";

    QSqlQuery query;
    query.exec(sql);

    QVector<Building> buildings;
    while(query.next()){
        QString name = query.value(0).toString();

        Building b(name);
        buildings.append(b);
    }

    return buildings;
}

bool Data::insertBuilding(QString name)
{
    QString sql = "INSERT INTO Building(name) "
                      "VALUES (:name)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":name", name);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::deleteBuilding(QString name)
{
    QString sql = "DELETE FROM Building where name= (:name)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":name", name);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateBuilding(QString name, QString curName)
{
    QString sql = "UPDATE Building SET "
                  "name = (:name) "
                  "WHERE name= (:curName)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":name", name);
    query.bindValue(":curName", curName);
    query.exec();

    return query.numRowsAffected() > 0;
}


QVector<Room> Data::selectRoomsByBuilding(QString bldgName)
{
    QString sql = "SELECT * FROM Room "
                  "WHERE bldgName= (:bldgName) "
                  "ORDER BY roomNum";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":bldgName", bldgName);
    query.exec();

    QVector<Room> rooms;
    while(query.next()){
        QString bldgName = query.value(0).toString();
        int roomNum = query.value(1).toInt();
        int capacity = query.value(2).toInt();


        Room r(bldgName, roomNum, capacity);
        rooms.append(r);
    }

    return rooms;
}

bool Data::insertRoom(
        QString bldgName, int roomNum, int capacity)
{
    QString sql = "INSERT INTO Room(bldgName, roomNum, capacity) "
                      "VALUES (:blgName, :roomNum, :capacity)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":bldgName", bldgName);
    query.bindValue(":roomNum", roomNum);
    query.bindValue(":capacity", capacity);

    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::deleteRoom(QString bldgName, int roomNum)
{
    QString sql = "DELETE FROM Room where bldgName= (:bldgName) "
                  "and roomNum= (:roomNum)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":bldgName", bldgName);
    query.bindValue(":roomNum", roomNum);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::updateRoom(
        QString bldgName, int roomNum, int capacity,
        QString curBldgName, int curRoomNum)
{
    QString sql = "UPDATE Room SET "
                  "bldgName = (:bldgName), roomNum= (:roomNum),"
                  "capacity= (:capacity) "
                  "WHERE bldgName= (:curBldgName) "
                  "AND roomNum= (:curRoomNum)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":bldgName", bldgName);
    query.bindValue(":roomNum", roomNum);
    query.bindValue(":capacity", capacity);
    query.bindValue(":curBldgName", curBldgName);
    query.bindValue(":curRoomNum", curRoomNum);
    query.exec();

    return query.numRowsAffected() > 0;
}


bool Data::isRegistered(int sid, QString year, QString semester)
{
    QString sql = "SELECT * FROM Registration "
                  "where sid= (:eid) "
                  "and year= (:year) "
                  "and semester= (:semester)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":sid", sid);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);

    query.exec();

    return query.first();
}

bool Data::insertRegister(int sid, QString year, QString semester)
{
    QString sql = "INSERT INTO Registration(sid, year, semester) "
                      "VALUES (:sid, :year, :semester)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":sid", sid);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);

    query.exec();

    return query.numRowsAffected() > 0;
}


bool Data::isTuitionPaid(int sid, QString year, QString semester)
{
    QString sql = "SELECT * FROM Tuition "
                  "where sid= (:eid) "
                  "and year= (:year) "
                  "and semester= (:semester)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":sid", sid);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);

    query.exec();

    return query.first();
}

bool Data::insertTuition(int sid, QString year, QString semester)
{
    QString sql = "INSERT INTO Tuition(sid, year, semester) "
                      "VALUES (:sid, :year, :semester)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":sid", sid);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);

    query.exec();

    return query.numRowsAffected() > 0;
}


QVector<int> Data::selectStudentSections(
        int sid, QString year, QString semester)
{
    QString sql = "SELECT sectionId FROM StudentSections "
                  "WHERE sid= (:sid) "
                  "AND year= (:year) "
                  "AND semester= (:semester)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":sid", sid);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.exec();

    QVector<int> sectionIds;
    while(query.next()){
        int sectionId = query.value(0).toInt();

        sectionIds.append(sectionId);
    }

    return sectionIds;
}

bool Data::insertStudentSections(
        int sid, int sectionId, QString year, QString semester)
{
    QString sql = "INSERT INTO StudentSections(sid, sectionId, "
                  "year, semester) "
                      "VALUES (:sid, :sectionId, "
                  ":year, :semester)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":sid", sid);
    query.bindValue(":sectionId", sectionId);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.exec();

    return query.numRowsAffected() > 0;
}

bool Data::deleteStudentSection(
        int sid, int sectionId, QString year, QString semester)
{
    QString sql = "DELETE FROM StudentSections where sid= (:sid) "
                  "and sectionId= (:sectionId) "
                  "and year= (:year) "
                  "and semester= (:semester)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":sid", sid);
    query.bindValue(":sectionId", sectionId);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.exec();

    return query.numRowsAffected() > 0;

}

bool Data::insertStudentGrade(
        int sid, int sectionId, QString year, QString semester,
        QString grade)
{
    QString sql = "UPDATE StudentSections SET "
                  "grade = (:grade) "
                  "WHERE sid= (:sid) "
                  "AND sectionId= (:sectionId) "
                  "AND year= (:year) "
                  "AND semester= (:semester)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":grade", grade);
    query.bindValue(":sid", sid);
    query.bindValue(":sectionId", sectionId);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.exec();

    return query.numRowsAffected() > 0;

}

QVector<int> Data::selectProfessorSections(
        int profEid, QString year, QString semester)
{
    QString sql = "SELECT sectionId FROM Sections "
                  "WHERE profEid= (:profEid) "
                  "AND year= (:year) "
                  "AND semester= (:semester)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":profEid", profEid);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.exec();

    QVector<int> sectionIds;
    while(query.next()){
        int sectionId = query.value(0).toInt();

        sectionIds.append(sectionId);
    }

    return sectionIds;
}

bool Data::insertProfessorSection(
        int profEid, int sectionId, QString year, QString semester)
{
    QString sql = "INSERT INTO ProfessorSections(profEid, sectionId, "
                  "year, semester) "
                      "VALUES (:profEid, :sectionId, "
                  ":year, :semester)";

    QSqlQuery query;

    query.prepare(sql);
    query.bindValue(":profEid", profEid);
    query.bindValue(":sectionId", sectionId);
    query.bindValue(":year", year);
    query.bindValue(":semester", semester);
    query.exec();

    return query.numRowsAffected() > 0;
}


QVector<Course> Data::selectPreReqs(QString courseName)
{
    QString sql = "SELECT * FROM Prerequisite "
                  "WHERE courseName= (:courseName) ";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":courseName", courseName);
    query.exec();

    QVector<Course> courses;
    while(query.next()){
        QString majorName = query.value(0).toString();
        QString courseName = query.value(1).toString();
        int units = query.value(2).toInt();

        Course c(majorName, courseName, units);
        courses.append(c);
    }

    return courses;
}
