#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QDir>
#include "data.h"
#include "student.h"
#include "employee.h"

struct User {
    int id;
    QString password;
    QString type;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void add_college_btn();
    Employee tempEmployee;
    void setUser(int id, QString pass, QString type);
    Room tempRoom;
  


private slots:
    void on_addCollege_clicked();

    void on_pushButton_15_clicked();

    void on_addMajor_clicked();

    void on_addCourse_clicked();

    void on_addSection_clicked();

    void on_editUnoversity_clicked();

    void on_removeUniversity_clicked();


    void on_addEmployee_clicked();

    void on_editEmployee_clicked();

    void on_deleteEmployee_clicked();

    void on_employeeSave_clicked();
    void on_employeeSave_2_clicked();
    void populate_adminListTableWidget();

private slots:
    void on_superAdminSave_clicked();
    void on_roomsTable_clicked(const QModelIndex &i);
    void on_addAdmin_clicked();

    void on_deleteAdmin_clicked();

    void on_editAdmin_clicked();

    void on_addAdminEnterPushButton_clicked();

    void on_editAdminEnterPushButton_clicked();

    void populate_roomsListTableWidget();
    void on_findStudentEnter_clicked();

    void on_editOrViewStudent_clicked();

    void on_deleteStudent_clicked();

    void on_saveStudentData_clicked();

    void on_omboBox_80_activated(const QString &arg1);

    void on_saveStudentGrade_clicked();

    void on_deleteRoom_clicked();

    void on_editRoom_clicked();

    void on_pushButton_clicked();

    void on_saveRoom_clicked();

    void on_saveRoom_3_clicked();

    void on_editBuilding_clicked();

    void on_addBuilding_clicked();

    void on_saveBuilding_2_clicked();

    void on_saveBuilding_clicked();

    void on_deleteBuilding_clicked();

    void on_collegeBox_currentTextChanged(const QString &arg1);

    void on_departmentBox_currentTextChanged(const QString &arg1);

    void on_majorBox_currentTextChanged(const QString &arg1);

    void on_courseBox_currentTextChanged(const QString &arg1);

    void on_studentCollegeComboBox_currentTextChanged(const QString &arg1);

    void on_studentDepartmentComboBox_currentTextChanged(const QString &arg1);

    void on_studentMajorComboBox_currentTextChanged(const QString &arg1);

    void on_studentCourseComboBox_currentTextChanged(const QString &arg1);

    void on_buildingsComboBox_currentTextChanged(const QString &arg1);

    void on_employeeTable_clicked(const QModelIndex &index);

    void on_deleteAdminEnterPushButton_clicked();

    void on_semesterEnter_clicked();

    void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Data data;

    User user;

    void PopulateUniversityTable();
    void PopulateStudentCourseTable();
    void PopulateEmployeeTable();
    void PopulateAdminTable();
    void PopulateStudentsTable();
    void PopulateRoomsTable();
};

#endif // MAINWINDOW_H
