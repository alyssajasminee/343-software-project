#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addCollege_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_15_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_addMajor_clicked()
{
ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_addCourse_clicked()
{
ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_addSection_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_editUnoversity_clicked()
{

}

void MainWindow::on_removeUniversity_clicked()
{

}

void MainWindow::on_collegeBox_highlighted(const QString &arg1)
{

}

void MainWindow::on_majorBox_highlighted(const QString &arg1)
{

}

void MainWindow::on_courseBox_highlighted(const QString &arg1)
{

}

void MainWindow::on_sectionsBox_highlighted(const QString &arg1)
{

}

void MainWindow::on_yearBox_highlighted(const QString &arg1)
{

}

void MainWindow::on_semesterBox_highlighted(const QString &arg1)
{

}

void MainWindow::on_addEmployee_clicked()
{

}



void MainWindow::on_editEmployee_clicked()
{

}

void MainWindow::on_deleteEmployee_clicked()
{

}

void MainWindow::on_employeeSave_clicked()
{
    QString fName = ui->EmployeeFirstName->text();
    QString lName = ui->employeeLastName->text();
    QString middleI = ui->employeeMI->text();
    QString salary = ui->employeeSalary->text();


}

void MainWindow::on_deleteStudent_clicked()
{
    int iD = ui->studentIDentered->text().toInt();
    Data::deleteStudent(iD);
}
