#include "mainwindow.h"
#include "ui_mainwindow.h"
//TODO uncomment:
//#include "room.h"
#include "data.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<College> collegeList = data.selectColleges();
    ui->collegeBox->addItem("");
    ui->studentCollegeComboBox->addItem("");
    for (int i = 0; i < collegeList.size(); i++) {
        ui->collegeBox->addItem(collegeList[i].getName());
        ui->studentCollegeComboBox->addItem(collegeList[i].getName());
    }

    QVector<QString> yearList = {"2018", "2019", "2020"};
    ui->yearBox->addItem("");
    for (int i = 0; i < yearList.size(); i++) {
        ui->yearBox->addItem(yearList[i]);
    }

    QVector<QString> semesterList = {"Fall", "Spring", "Summer"};
    ui->semesterBox->addItem("");
    for (int i = 0; i < semesterList.size(); i++) {
        ui->semesterBox->addItem(semesterList[i]);
    }

    QVector<Building> buildingList = data.selectBuidings();
    ui->buildingsComboBox->addItem("");
    for (int i = 0; i < buildingList.size(); i++) {
        ui->buildingsComboBox->addItem(buildingList[i].getName());
    }
    ui->stackedWidget_2->setCurrentIndex(0);
    PopulateEmployeeTable();
    PopulateAdminTable();
    PopulateStudentsTable();

//    data.selectBuidings();
//    data.selectCourses();
//    data.selectDepartments();
//    data.selectMajors();
//    data.selectPreReqs();
//    data.selectProfessors();
//    data.selectProfessorSections();
//    data.selectRoomsByBuilding();
//    data.selectSectionById();
//    data.selectSections();
//    data.selectStudentById();
//    data.selectStudents();
//    data.selectStudentSections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PopulateUniversityTable() {
    QVector<Section> sectionList = data.selectSections(ui->courseBox->currentText(), ui->yearBox->currentText(), ui->semesterBox->currentText());
    int rows = sectionList.size();
    int cols = 9;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"Section ID","Course","Year","Semester","Start Time","End Time","Building","Room","Professor ID"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < sectionList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getSectionId()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getCourseName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getYear()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getSemester()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getStartTime()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getEndTime()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getBldgName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getRoomNum()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getProfEid()));
    }
    ui->universityTable->setModel(customModel);
    ui->universityTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::PopulateStudentCourseTable() {
    QVector<Section> sectionList = data.selectAllSections(ui->studentCourseComboBox->currentText());
    int rows = sectionList.size();
    int cols = 9;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"Section ID","Course","Year","Semester","Start Time","End Time","Building","Room","Professor ID"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < sectionList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getSectionId()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getCourseName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getYear()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getSemester()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getStartTime()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getEndTime()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getBldgName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getRoomNum()));
        index++;
        customModel->setItem(i, index, new QStandardItem(sectionList[i].getProfEid()));
    }
    ui->studentCourseTable->setModel(customModel);
    ui->studentCourseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::PopulateEmployeeTable() {
    QVector<Employee> employeeList = data.selectEmployees();
    int rows = employeeList.size();
    int cols = 6;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"ID","First","MI","Last","Title","Salary"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < employeeList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getEID()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getFirstName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getMiddleInitial()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getLastName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getTitle()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getSalary()));
    }
    ui->employeeTable->setModel(customModel);
    ui->employeeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::PopulateAdminTable() {
    QVector<Admin> adminList = data.selectAdmins();
    int rows = adminList.size();
    int cols = 2;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"ID","First","MI","Last","Title","Salary"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < adminList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(adminList[i].getID()));
        index++;
        customModel->setItem(i, index, new QStandardItem(adminList[i].getPassword()));
    }
    ui->adminTable->setModel(customModel);
    ui->adminTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::PopulateStudentsTable() {
    QVector<Student> studentList = data.selectStudents();
    int rows = studentList.size();
    int cols = 6;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"ID", "Password","First","MI","Last","Middle"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < studentList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(studentList[i].getId()));
        index++;
        customModel->setItem(i, index, new QStandardItem(studentList[i].getPass()));
        index++;
        customModel->setItem(i, index, new QStandardItem(studentList[i].getFirstName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(studentList[i].getMiddleInitial()));
        index++;
        customModel->setItem(i, index, new QStandardItem(studentList[i].getLastName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(studentList[i].getMajor()));
    }
    ui->studentsTable->setModel(customModel);
    ui->studentsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::PopulateRoomsTable() {
    QVector<Room> roomsList = data.selectRoomsByBuilding(ui->buildingsComboBox->currentText());
    int rows = roomsList.size();
    int cols = 3;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"Building", "Number", "Capacity"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < roomsList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(roomsList[i].getBldgName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(roomsList[i].getRoomNum()));
        index++;
        customModel->setItem(i, index, new QStandardItem(roomsList[i].getCapacity()));
    }
    ui->roomsTable->setModel(customModel);
    ui->roomsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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

//void MainWindow::on_deleteStudent_clicked()
//{
//    //TODO, be able to get this student from the TableWidget
//    //Make sure studentListTableWidget contains student ID

////    int ID = ;
////    Data::deleteStudent(ID);
//    //TODO also refresh tablewidget
//}

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
//{started}Populate table (method to fetch/refresh data)
//{started}Delete Room button
//{started}Edit Room button (create stacked widget {done} and populate other lineEdits)
//{started}Add Room button
//{started}Save Room button
//{started}Edit Building button
//{started}Delete Building Button
//{started}Save Building buttons



//fix
void MainWindow::on_deleteRoom_clicked()
{
    QString currentBuilding = ui->buildingsComboBox->currentText();
//    QString currentRoom = ui->roomsListTableWidget->currentItem()->text();
//    int roomNum = currentRoom.toInt();
//    Data::deleteRoom(currentBuilding, roomNum);
}
//fix
void MainWindow::on_editRoom_clicked()
{
    //Make visible:
    ui->editRoomStackedWidget->setCurrentIndex(1);

    //Populate:
   //QString currentRoom = ui->roomsTable->currentItem()->text();
}


void MainWindow::on_pushButton_clicked()
{

    ui->addRoomStackedWidget->setCurrentIndex(1);

}

//fix
void MainWindow::on_saveRoom_clicked()
{
    //int oldRoomNumber = ui->roomsListTableWidget->currentItem()->text().toInt();
    int newRoomNumber = ui->roomNumberLineEdit->text().toInt();
    QString currentBuilding = ui->buildingsComboBox->currentText();
    int cap = ui->spinBox_2->text().toInt();
   // Data::updateRoom(currentBuilding, newRoomNumber, cap, currentBuilding, oldRoomNumber);
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


void MainWindow::on_addEmployee_clicked()
{
 ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_employeeTable_clicked(const QModelIndex &i)
{
        int row = i.row();
        tempEmployee.setEID(ui->employeeTable->model()->data(ui->employeeTable->model()->index(row,0)).toInt());
        tempEmployee.setFirstName(ui->employeeTable->model()->data(ui->employeeTable->model()->index(row,1)).toString());
        tempEmployee.setMiddleInitial(ui->employeeTable->model()->data(ui->employeeTable->model()->index(row,2)).toString());
        tempEmployee.setLastName(ui->employeeTable->model()->data(ui->employeeTable->model()->index(row,3)).toString());
        tempEmployee.setTitle(ui->employeeTable->model()->data(ui->employeeTable->model()->index(row,4)).toString());
        tempEmployee.setSalary(ui->employeeTable->model()->data(ui->employeeTable->model()->index(row,4)).toInt());

}

void MainWindow::on_editEmployee_clicked()
{
ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_deleteEmployee_clicked()
{
   Data::deleteEmployee(tempEmployee.getEID());
}

void MainWindow::on_employeeSave_clicked()
{
    QString fName = ui->EmployeeFirstName->text();
    QString lName = ui->employeeLastName->text();
    QString middleI = ui->employeeMI->text();
    double salary = ui->employeeSalary->text().toDouble();
    Data::insertEmployee(fName, middleI, lName, " ", salary);

}
void MainWindow::on_employeeSave_2_clicked()
{
    QString fName = ui->EmployeeFirstName_2->text();
    QString lName = ui->employeeLastName_2->text();
    QString middleI = ui->employeeMI_2->text();
    double salary = ui->employeeSalary_2->text().toDouble();
    int id = tempEmployee.getEID();
    QString t = tempEmployee.getTitle();
    Data::updateEmployee(id, fName,  middleI,lName, t, salary);



}


//void MainWindow::on_deleteStudent_clicked()
//{
//    int iD = ui->studentIDentered->text().toInt();
//    Data::deleteStudent(iD);
//}

void MainWindow::on_collegeBox_currentTextChanged(const QString &arg1)
{
    ui->departmentBox->clear();
    QVector<Department> departmentList = data.selectDepartments(arg1);
    ui->departmentBox->addItem("");
    for (int i = 0; i < departmentList.size(); i++) {
        ui->departmentBox->addItem(departmentList[i].getDeptName());
    }
}

void MainWindow::on_departmentBox_currentTextChanged(const QString &arg1)
{
    ui->majorBox->clear();
    QVector<Major> majorsList = data.selectMajors(arg1);
    ui->majorBox->addItem("");
    for (int i = 0; i < majorsList.size(); i++) {
        ui->majorBox->addItem(majorsList[i].getMajorName());
    }
}

void MainWindow::on_majorBox_currentTextChanged(const QString &arg1)
{
    ui->courseBox->clear();
    QVector<Course> courseList = data.selectCourses(arg1);
    ui->courseBox->addItem("");
    for (int i = 0; i < courseList.size(); i++) {
        ui->courseBox->addItem(courseList[i].getCourseName());
    }
}

void MainWindow::on_courseBox_currentTextChanged(const QString &arg1)
{
    ui->sectionsBox->clear();
    QVector<Section> sectionList = data.selectSections(arg1, ui->yearBox->currentText(), ui->semesterBox->currentText());
    ui->sectionsBox->addItem("");
    for (int i = 0; i < sectionList.size(); i++) {
        ui->sectionsBox->addItem(QString::number(sectionList[i].getSectionId()));
    }
    PopulateUniversityTable();
}

void MainWindow::on_sectionsBox_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_studentCollegeComboBox_currentTextChanged(const QString &arg1)
{
    ui->studentDepartmentComboBox->clear();
    QVector<Department> departmentList = data.selectDepartments(arg1);
    ui->studentDepartmentComboBox->addItem("");
    for (int i = 0; i < departmentList.size(); i++) {
        ui->studentDepartmentComboBox->addItem(departmentList[i].getDeptName());
    }
}

void MainWindow::on_studentDepartmentComboBox_currentTextChanged(const QString &arg1)
{
    ui->studentMajorComboBox->clear();
    QVector<Major> majorsList = data.selectMajors(arg1);
    ui->studentMajorComboBox->addItem("");
    for (int i = 0; i < majorsList.size(); i++) {
        ui->studentMajorComboBox->addItem(majorsList[i].getMajorName());
    }
}

void MainWindow::on_studentMajorComboBox_currentTextChanged(const QString &arg1)
{
    ui->studentCourseComboBox->clear();
    QVector<Course> courseList = data.selectCourses(arg1);
    ui->studentCourseComboBox->addItem("");
    for (int i = 0; i < courseList.size(); i++) {
        ui->studentCourseComboBox->addItem(courseList[i].getCourseName());
    }
}

void MainWindow::on_studentCourseComboBox_currentTextChanged(const QString &arg1)
{
    PopulateStudentCourseTable();
}

void MainWindow::on_buildingsComboBox_currentTextChanged(const QString &arg1)
{
    PopulateRoomsTable();
}

