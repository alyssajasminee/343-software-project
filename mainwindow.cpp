#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
#include "student.h"
#include "room.h"

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

//TODO: Merge with master code
//TODO: equivalent to selectItem() (see Rooms tab)
//TODO: Hard-code university name? (but ummm "make configurable")


////////////////////////   Super Admin Tab   ////////////////////////

void MainWindow::on_addAdmin_clicked()
{
    //make text box visible
    ui->addAdminStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addAdminEnterPushButton_clicked()
{
    QString adminPassword = ui->newAdminLineEdit->text();
    Data::insertAdmin(adminPassword);
}

void MainWindow::on_deleteAdmin_clicked()
{
    ui->deleteAdminStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_deleteAdminEnterPushButton_clicked()
{
    int adminID = ui->deleteAdminLineEdit->text().toInt();
    Data::deleteAdmin(adminID);
}

void MainWindow::on_editAdmin_clicked()
{
    ui->editAdminStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_editAdminEnterPushButton_clicked()
{
    int ID = ui->editAdminIDLineEdit->text().toInt();
    QString newPassword = ui->editAdminPasswordLineEdit->text();
    Data::updateAdmin(ID, newPassword);
}


/////////////////////////////   ADMIN TAB   ////////////////////////////

void MainWindow::on_findStudentEnter_clicked()
{
    int ID = ui->studentIDLineEdit->text().toInt();
    Student stu = Data::selectStudentById(ID);
    ui->studentInfoStackedWidget->setCurrentIndex(1);
    ui->studentFirstNameLineEdit->setText(stu.getFirstName());
    ui->studentLastNameLineEdit->setText(stu.getLastName());
    ui->studentMILineEdit->setText(stu.getMiddleInitial());
    ui->label_72->setText(QString::number(stu.getId()));
}

void MainWindow::on_deleteStudent_clicked()
{
    int ID = ui->studentIDLineEdit->text().toInt();
    Data::deleteStudent(ID);
    populateStudentsTable();
}

void MainWindow::on_saveStudentData_clicked()
{
    QString first = ui->studentFirstNameLineEdit->text();
    QString last = ui->studentLastNameLineEdit->text();
    QString mid = ui->studentMILineEdit->text();
    QString major = ""; //Workaround; student doesn't need major
    QString password = "password"; //Default. This will be changed elsewhere
    Data::insertStudent(password, first, mid, last, major);
    populateStudentsTable();
}

void MainWindow::on_semesterEnter_clicked()
{
    int ID = ui->label_72->text().toInt();
    QString year = ui->yearLineEdit->text();
    QString semester = ui->semesterLineEdit->text();
    //Update radio buttons to reflect if tuition was paid (name: radioButton; value: true if registered)
    if (Data::isTuitionPaid(ID, year, semester)){
        //set tuition radio button to true
        ui->radioButton->setChecked(true);
    }
    else {
        ui->radioButton_2->setChecked(true);
    }

    //Update studentGradeCourseComboBox to show this chosen semester's courses
    QVector<int> sections = Data::selectStudentSections(ID);
    int i = 0;
    for (int i = 0; i < sections.size(); ++i) {
        QString section = QString::number(sections[i]);
        ui->studentgradeCourseComboBox->insertItem(i, section);
    }
    //NOT USING THIS VERSION ANYMORE:
//    QVector<QString> transcript = Data::SelectTranscript(ID);
//    int i = 0;
//    for (int i = 0; i < transcript.size(); ++i) {
//        ui->studentgradeCourseComboBox->insertItem(i, transcript[i].getSection(i));
//    }
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    int ID = ui->label_72->text().toInt();
    QString year = ui->yearLineEdit->text();
    QString semester = ui->semesterLineEdit->text();
    if (checked) {
        Data::insertTuition(ID, year, semester);
    }
}

void MainWindow::on_saveStudentGrade_clicked()
{
    int student_ID = ui->label_72->text().toInt();
    QString year = ui->yearLineEdit->text();
    QString semester = ui->semesterLineEdit->text();

//    QString courseName = ui->studentGradeCourseComboBox->currentText();
    int sectionId = ui->studentGradeCourseComboBox->currentText().toInt();
    QString grade = ui->studentGradeNewGradeComboBox->currentText();

    //Now update the grade:
    Data::insertStudentGrade(student_ID, sectionId, year,semester, grade);
}


//////////////////////   Rooms Tab    /////////////////////////////

//TODO: currentItem() was a function that worked for QTableWidgets
//It does not work for QTableViews.
//Need to change this so that it works w/ QTableViews

void MainWindow::on_deleteRoom_clicked()
{
    QString currentBuilding = ui->buildingsComboBox->currentText();
    QString currentRoom = ui->roomsTable->currentItem()->text();
    int roomNum = currentRoom.toInt();
    Data::deleteRoom(currentBuilding, roomNum);
}

void MainWindow::on_editRoom_clicked()
{
    //Make visible:
    ui->editRoomStackedWidget->setCurrentIndex(1);

    //Populate:
    QString currentRoom = ui->roomsTable->currentItem()->text();
}

/* BEWARE this is the Add Room button */
void MainWindow::on_pushButton_clicked()
{
    //Make visible:
    ui->addRoomStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_saveRoom_clicked()
{
    int oldRoomNumber = ui->roomsTable->currentItem()->text().toInt();
    int newRoomNumber = ui->roomNumberLineEdit->text().toInt();
    QString currentBuilding = ui->buildingsComboBox->currentText();
    int cap = ui->spinBox_2->text().toInt();
    Data::updateRoom(currentBuilding, newRoomNumber, cap, currentBuilding, oldRoomNumber);
}

void MainWindow::on_saveRoom_3_clicked()
{
    int roomNumber = ui->roomNumberLineEdit->text().toInt();
    QString currentBuilding = ui->buildingsComboBox->currentText();
    int cap = ui->spinBox_2->text().toInt();
    Data::insertRoom(currentBuilding, roomNumber, cap);
}

void MainWindow::on_editBuilding_clicked()
{
    ui->editBuildingStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addBuilding_clicked()
{
    ui->addBuildingStackedWidget->setCurrentIndex(0);
}

void MainWindow::on_saveBuilding_2_clicked()
{
    QString bldgName = ui->addBuildingNameLineEdit->text();
    Data::insertBuilding(bldgName);
}

void MainWindow::on_saveBuilding_clicked()
{
    QString oldName = ui->buildingsComboBox->currentText();
    QString bldgName = ui->editBuildingNameLineEdit->text();
    Data::updateBuilding(bldgName, oldName);
}

void MainWindow::on_deleteBuilding_clicked()
{
    QString bldgName = ui->buildingsComboBox->currentText();
    Data::deleteBuilding(bldgName);
}
