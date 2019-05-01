#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
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

    void on_deleteStudent_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
