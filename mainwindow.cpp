#include "mainwindow.h"
#include "ui_mainwindow.h"
//TODO uncomment:
//#include "room.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUser(int id, QString pass, QString type) {
    user.id = id;
    user.password = pass;
    user.type = type;
}

void MainWindow::PopulateUniversityTable() {
    QVector<Section> sectionList = data.selectSections(ui->courseBox->currentText(), ui->yearBox->currentText(), ui->semesterBox->currentText());
    int rows = sectionList.size();
    int cols = 9;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"Section ID","Course","Year","Semester","Start","End","Building","Room","Prof. ID"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < sectionList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(QString::number(sectionList[i].getSectionId())));
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
        customModel->setItem(i, index, new QStandardItem(QString::number(sectionList[i].getRoomNum())));
        index++;
        customModel->setItem(i, index, new QStandardItem(QString::number(sectionList[i].getProfEid())));
    }
    ui->universityTable->setModel(customModel);
    ui->universityTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::PopulateStudentCourseTable() {
    QVector<Section> sectionList = data.selectAllSections(ui->studentCourseComboBox->currentText());
    int rows = sectionList.size();
    int cols = 9;
    QStandardItemModel *customModel = new QStandardItemModel(rows,cols,this);
    QVector<QString> headerList = {"Section ID","Course","Year","Semester","Start","End","Building","Room","Prof ID"};
    for (int i = 0; i < cols; i++) {
        customModel->setHorizontalHeaderItem(i, new QStandardItem(headerList[i]));
    }
    for (int i = 0; i < sectionList.size(); i++) {
        int index = 0; // Column index
        customModel->setItem(i, index, new QStandardItem(QString::number(sectionList[i].getSectionId())));
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
        customModel->setItem(i, index, new QStandardItem(QString::number(sectionList[i].getRoomNum())));
        index++;
        customModel->setItem(i, index, new QStandardItem(QString::number(sectionList[i].getProfEid())));
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
        customModel->setItem(i, index, new QStandardItem(QString::number(employeeList[i].getEID())));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getFirstName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getMiddleInitial()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getLastName()));
        index++;
        customModel->setItem(i, index, new QStandardItem(employeeList[i].getTitle()));
        index++;
        customModel->setItem(i, index, new QStandardItem(QString::number(employeeList[i].getSalary())));
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
        customModel->setItem(i, index, new QStandardItem(QString::number(adminList[i].getID())));
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
        customModel->setItem(i, index, new QStandardItem(QString::number(studentList[i].getId())));
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
        customModel->setItem(i, index, new QStandardItem(QString::number(roomsList[i].getRoomNum())));
        index++;
        customModel->setItem(i, index, new QStandardItem(QString::number(roomsList[i].getCapacity())));
    }
    ui->roomsTable->setModel(customModel);
    ui->roomsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_superAdminSave_clicked()
{
    //Take in information from the associated QLineEdit
    //QString newPassword = ui->superAdminTab->text();
}

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
    PopulateStudentsTable();
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
    QString major = ""; //Workaround; student doesn't need major
    QString password = "password"; //Default. This will be changed elsewhere
    Data::insertStudent(password, first, mid, last, major);
    PopulateStudentsTable();
}

void MainWindow::on_semesterEnter_clicked()
{
    int ID = ui->label_72->text().toInt();
    QString year = ui->yearLineEdit->text();
    QString semester = ui->semesterLineEdit->text();
    if (Data::isTuitionPaid(ID, year, semester)){
        //set tuition radio button to true
        ui->radioButton->setChecked(true);
    }
    else {
        ui->radioButton_2->setChecked(true);
    }

    //Update studentGradeCourseComboBox to show this chosen semester's courses
    QVector<int> sections = data.selectStudentSections(ID, year, semester);
    int i = 0;
    for (int i = 0; i < sections.size(); ++i) {
        QString section = QString::number(sections[i]);
        ui->studentGradeCourseComboBox->insertItem(i, section);
    }
    
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



void MainWindow::on_pushButton_clicked()

{



    ui->addRoomStackedWidget->setCurrentIndex(1);



}

void MainWindow::on_roomsTable_clicked(const QModelIndex &i)

{

    int row = i.row();

    tempRoom.setRoomNum(ui->roomsTable->model()->data(ui->roomsTable->model()->index(row,1)).toInt());

    tempRoom.setBldgName(ui->roomsTable->model()->data(ui->roomsTable->model()->index(row,0)).toString());

    tempRoom.setCapacity(ui->roomsTable->model()->data(ui->roomsTable->model()->index(row,2)).toInt());



}

void MainWindow::on_editRoom_clicked()

{

    QString r;

    ui->roomNumberLineEdit->setText(r.setNum(tempRoom.getRoomNum()));

    ui->spinBox_2->setValue(tempRoom.getCapacity());

    ui->editRoomStackedWidget->setCurrentIndex(1);



}

void MainWindow::on_saveRoom_clicked()

{



    int newRoomNumber = ui->roomNumberLineEdit->text().toInt();

    int cap = ui->spinBox_2->text().toInt();

    Data::updateRoom(tempRoom.getBldgName(), newRoomNumber, cap, tempRoom.getBldgName(), tempRoom.getRoomNum());

    PopulateRoomsTable();

    ui->editRoomStackedWidget->setCurrentIndex(0);

    ui->roomNumberLineEdit->clear();

    ui->spinBox_2->clear();



}

void MainWindow::on_saveRoom_3_clicked()

{

    int roomNumber = ui->roomNumberLineEdit_3->text().toInt();

    QString currentBuilding = ui->buildingsComboBox->currentText();

    int cap = ui->spinBox_4->text().toInt();

    Data::insertRoom(currentBuilding, roomNumber, cap);

    PopulateRoomsTable();

    ui->addRoomStackedWidget->setCurrentIndex(0);

    ui->roomNumberLineEdit_3->clear();

    ui->spinBox_4->clear();

}

void MainWindow::on_deleteRoom_clicked()

{

    Data::deleteRoom(tempRoom.getBldgName(), tempRoom.getRoomNum());

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

     ui->addBuildingStackedWidget->setCurrentIndex(1);

     ui->addBuildingNameLineEdit->clear();

}

void MainWindow::on_saveBuilding_clicked()

{

    QString oldName = ui->buildingsComboBox->currentText();

    QString bldgName = ui->editBuildingNameLineEdit->text();

   Data::updateBuilding(bldgName, oldName);

    ui->editBuildingStackedWidget->setCurrentIndex(1);

    ui->editBuildingNameLineEdit->clear();

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
   data.deleteEmployee(tempEmployee.getEID());
   PopulateEmployeeTable();
}

void MainWindow::on_employeeSave_clicked()
{
    QString fName = ui->EmployeeFirstName->text();
    QString lName = ui->employeeLastName->text();
    QString middleI = ui->employeeMI->text();
    double salary = ui->employeeSalary->text().toDouble();
    data.insertEmployee(fName, middleI, lName, " ", salary);
    PopulateEmployeeTable();
}
void MainWindow::on_employeeSave_2_clicked()
{
    QString fName = ui->EmployeeFirstName_2->text();
    QString lName = ui->employeeLastName_2->text();
    QString middleI = ui->employeeMI_2->text();
    double salary = ui->employeeSalary_2->text().toDouble();
    int id = tempEmployee.getEID();
    QString t = tempEmployee.getTitle();
    data.updateEmployee(id, fName,  middleI,lName, t, salary);
    PopulateEmployeeTable();
}

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

//void MainWindow::on_deleteStudent_clicked()
//{
//    int iD = ui->studentIDentered->text().toInt();
//    Data::deleteStudent(iD);
//}

void MainWindow::on_buildingsComboBox_currentTextChanged(const QString &arg1)
{
    ui->departmentBox->clear();
    QVector<Department> departmentList = data.selectDepartments(arg1);
    ui->departmentBox->addItem("");
    for (int i = 0; i < departmentList.size(); i++) {
        ui->departmentBox->addItem(departmentList[i].getDeptName());
    }
    PopulateRoomsTable();
}

void MainWindow::on_courseBox_currentTextChanged(const QString &arg1)
{
    PopulateUniversityTable();
}
