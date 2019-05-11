#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "data.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    void Login(int id, QString pass);

private slots:
    void on_LoginButton_clicked();

private:
    Ui::login *ui;
    Data data;
    MainWindow mainWindow;
};

#endif // LOGIN_H
