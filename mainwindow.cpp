#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
#include "student.h"

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

void MainWindow::on_superAdminSave_clicked()
{
    //Take in information from the associated QLineEdit
    QString newPassword = ui-> superAdminPasswordLineEdit ->text();

    //Save that information
    //TODO create this function
    //Data::newSuperAdminPassword(newPassword);

    //Update currently displayed information
    ui->label_60->setText(newPassword);
}

void MainWindow::on_addAdmin_clicked()
{
    //make text box visible
    ui->addAdminStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addAdminEnterPushButton_clicked()
{
    QString adminName = ui->newAdminLineEdit->text();
    Data::insertAdmin(adminName);
    //TODO also update table
}

//TODO MAY NEED TO REWRITE THIS FUNCTION
void MainWindow::on_deleteAdmin_clicked()
{
    //TODO: need admin ID number to throw into this function
    QString currentAdmin = ui->adminListTableWidget->currentItem()->text();
//    int adminID = ui->adminListTableWidget->currentItem()->text().toInt();
 //   Data::deleteAdmin(adminID);
    //TODO update table
}

void MainWindow::on_editAdmin_clicked()
{
    //Set to visible
    ui->editAdminStackedWidget->setCurrentIndex(1);
}

void MainWindow::on_editAdminEnterPushButton_clicked()
{
    //TODO: Need admin ID to put in
    int ID = 0;
    //ID = ; //??
    QString newName = ui->editAdminLineEdit->text();
    Data::updateAdmin(ID, newName);
    //TODO update table
}


//TODO Admin Tab to-do:
//{}Write function to pull in updated data for studentListTableWidget
//      ...note this also means structuring what that table looks like Make sure it has student ID as an entry
//{started}Populate line edits etc (first name, etc) upon clicking student in studentListTableView (and edit button)
//{started}Ditto upon finding student by ID
//{started}Add Student button functionality
//{started}Delete Student button functionality
//{started}Edit Student button functionality
//{started}Save button functionality
//{started, comments only} Semester combo box functionality
//{started}Student Grade Save button functionality

void MainWindow::on_findStudentEnter_clicked()
{
    int ID = ui->studentIDLineEdit->text().toInt();
    //TODO: any checking to ensure student is actually there?
    //use exceptions?
    Student stu = Data::selectStudentById(ID);
    ui->studentInfoStackedWidget->setCurrentIndex(1);
    ui->studentFirstNameLineEdit->setText(stu.getFirstName());
    ui->studentLastNameLineEdit->setText(stu.getLastName());
    ui->studentMILineEdit->setText(stu.getMiddleInitial());
    ui->label_72->setText(QString::number(stu.getId()));
    //TODO isRegistered() functionality to Student class --for University
//    if (stu.isRegistered())     ui->radioButton_3->setChecked(true);
//    else ui->radioButton_4->setChecked(true);
    //TODO: populate studentSemesterListComboBox (need a StudentSections class for this)
//    StudentSections ss = ;
//    int i = 0;
//    for (StudentSections s : ss) {
//        ui->studentSemesterListComboBox->insertItem(i, s.getSection(i));
//        ++i;
//    }
}

void MainWindow::on_editOrViewStudent_clicked()
{
    //TODO, be able to get this student from the TableWidget
    //Make sure studentListTableWidget contains student ID

 /*
  * //Probably useless junk:
    QString studentName = ui->studentListTableWidget->currentItem()->text();
    QVector<Student> students = Data::selectStudents();
    int size = students.size();
    int numFound = 0;
    QVector<int> indices = QVector<int>();
    //TODO: Test this!!
    for (int i = 0; i < size; ++i) {
        QString fullName = students[i].getFirstName() + " "
                + students[i].getMiddleInitial() + " "
                + students[i].getLastName();
        if (fullName == studentName) {
            indices.push_back(i);
            ++numFound;
        }
    } //end of for loop
    if (numFound > 1) { //need to differentiate
        for (int i = 0; i < indices.size(); ++i) {

        }
    }
 */

//    Student stu = Student(); //TODO get rid of this line later
//    ui->studentInfoStackedWidget->setCurrentIndex(1);
//    ui->studentFirstNameLineEdit->setText(stu.getFirstName());
//    ui->studentLastNameLineEdit->setText(stu.getLastName());
//    ui->studentMILineEdit->setText(stu.getMiddleInitial());
//    ui->label_72->setText(QString::number(stu.getId()));
//    //TODO isRegistered() functionality to Student class -- for University
////    if (stu.isRegistered())     ui->radioButton_3->setChecked(true);
////    else ui->radioButton_4->setChecked(true);
//    //TODO: populate studentSemesterListComboBox
    //TODO: populate studentSemesterListComboBox (need a StudentSections class for this)
//    StudentSections ss = ;
//    int i = 0;
//    for (StudentSections s : ss) {
//        ui->studentSemesterListComboBox->insertItem(i, s.getSection(i));
//        ++i;
//    }
}

void MainWindow::on_deleteStudent_clicked()
{
    //TODO, be able to get this student from the TableWidget
    //Make sure studentListTableWidget contains student ID

//    int ID = ;
//    Data::deleteStudent(ID);
    //TODO also refresh tablewidget
}

void MainWindow::on_saveStudentData_clicked()
{
    QString first = ui->studentFirstNameLineEdit->text();
    QString last = ui->studentLastNameLineEdit->text();
    QString mid = ui->studentMILineEdit->text();
//TODO:     QString major = ; //Clarify if we need this
    bool isReg = ui->radioButton_3->isChecked();
//    QString password = ""; //?? Why is this in the next line?
    //TODO why does student have a password at all?? just needs an ID
//    Data::insertStudent(password, first, mid, last, major);
    //TODO update table widget
}

void MainWindow::on_omboBox_80_activated(const QString &arg1)
{
    //TODO
    //QString value sent in is the year and semester to see about tuition payment or grades
    //Update radio buttons to reflect if tuition was paid (name: radioButton; value: true if registered)
    //Update studentGradeCourseComboBox to show this chosen semester's courses
}

void MainWindow::on_saveStudentGrade_clicked()
{
    QString course = ui->studentGradeCourseComboBox->currentText();
    QString grade = ui->studentGradeNewGradeComboBox->currentText();
    //Now update the grade:
    //TODO we don't have a transcript for the Student class...
}


//TODO Rooms tab to-do:
//Rename buttons and lineEdits
//Populate table (method to fetch/refresh data)
//Delete Room button
//Edit Room button (create stacked widget and populate other lineEdits)
//Save Building button
//Room Occupancy spin box limits and functionality?
//Save Room button
