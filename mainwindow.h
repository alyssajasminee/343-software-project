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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void on_deleteStudent_clicked();

    void on_saveStudentData_clicked();

    void on_omboBox_80_activated(const QString &arg1);

    void on_saveStudentGrade_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
