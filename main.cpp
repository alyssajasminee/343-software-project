#include "mainwindow.h"
#include <QApplication>

#include "database.h"
#include "data.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Database db;

    //insert employee
//    Data::insertEmployee("emp", "emp", "emp", "professor", 55555.55f);

    //***********************
    //insert college
    const int MAX_COLLEGES = 10;
    if(Data::isEmployee(1) && Data::collegeCount() < MAX_COLLEGES)
        Data::insertCollege("Natural Science", 1);
    else {
        qDebug()<<"DEAN NOT AN EMPLOYEE"
               <<"OR MAX REACHED";
    }

    //select colleges
//    Data::selectColleges();

     //insert admin
//    Data::insertAdmin("insert admin");
    //return student id
//    Data::insertStudent("getid", "getid", "getid", "getid");

    //update student
//    Data::updateStudent(1001, "change", "change", "change", "change");
//    QVector<Student> s = StudentData::selectStudents();
//    for(Student st : s){
//        qDebug()<<"ID = "<<st.getId()
//               <<"PASSWORD = "<<st.getPass()
//              <<"FIRST NAME = "<<st.getFirstName()
//             <<"MI = "<<st.getMiddleInitial()
//            <<"LNAME = "<<st.getLastName();
//    }

//    StudentData::insertStudent("4321", "nancy", "n", "nielsen");
//    bool login = StudentData::authenticate(1000, "pass");
//    if(login)
//        qDebug()<<"Login Success\n";
//    else
//        qDebug()<<"Login Failed\n";

    w.show();

    return a.exec();
}
