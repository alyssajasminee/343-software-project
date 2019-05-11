#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::Login(int id, QString pass)
{
    if (data.superuserLogin(id, pass)) {
        mainWindow.setUser(id, pass, "Super Admin");
        this->close();
        mainWindow.show();
    } else if (data.adminLogin(id, pass)) {
        mainWindow.setUser(id, pass, "Admin");
        this->close();
        mainWindow.show();
    } else if (data.studentLogin(id, pass)) {
        mainWindow.setUser(id, pass, "Student");
        this->close();
        mainWindow.show();
    }
}

void login::on_LoginButton_clicked()
{
    QString idString = ui->UserNameInput->text();
    QString password = ui->PasswordInput->text();
    Login(idString.toInt(), password);
}
