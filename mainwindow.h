#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QDir>
#include "college.h"
#include "database.h"

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

private slots:
    void on_addCollege_clicked();

    void on_pushButton_15_clicked();



    void on_addMajor_clicked();

    void on_addCourse_clicked();

    void on_addSection_clicked();

    void on_editUnoversity_clicked();

    void on_removeUniversity_clicked();

    void on_collegeBox_highlighted(const QString &arg1);

    void on_majorBox_highlighted(const QString &arg1);

    void on_courseBox_highlighted(const QString &arg1);

    void on_sectionsBox_highlighted(const QString &arg1);

    void on_yearBox_highlighted(const QString &arg1);

    void on_semesterBox_highlighted(const QString &arg1);

    void on_addEmployee_clicked();



    void on_editEmployee_clicked();

    void on_deleteEmployee_clicked();

    void on_employeeSave_clicked();

    void populate_roomsListTableWidget();

private slots:
    void on_superAdminSave_clicked();

    void on_addAdmin_clicked();

    void on_deleteAdmin_clicked();

    void on_editAdmin_clicked();

    void on_addAdminEnterPushButton_clicked();

    void on_editAdminEnterPushButton_clicked();

    void on_findStudentEnter_clicked();

    void on_editOrViewStudent_clicked();

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

private:
    Ui::MainWindow *ui;
    Database *database;
    QVector<College> collegeList;
};

#endif // MAINWINDOW_H
