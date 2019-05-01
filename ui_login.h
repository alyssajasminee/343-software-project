/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *passwordLabel;
    QLineEdit *PasswordInput;
    QLabel *userNameLabel;
    QPushButton *LoginButton;
    QLineEdit *UserNameInput;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(790, 439);
        passwordLabel = new QLabel(login);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(80, 230, 141, 16));
        PasswordInput = new QLineEdit(login);
        PasswordInput->setObjectName(QString::fromUtf8("PasswordInput"));
        PasswordInput->setGeometry(QRect(80, 250, 591, 31));
        PasswordInput->setEchoMode(QLineEdit::Password);
        userNameLabel = new QLabel(login);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setGeometry(QRect(80, 170, 141, 16));
        LoginButton = new QPushButton(login);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        LoginButton->setGeometry(QRect(510, 300, 75, 31));
        QFont font;
        font.setPointSize(7);
        LoginButton->setFont(font);
        UserNameInput = new QLineEdit(login);
        UserNameInput->setObjectName(QString::fromUtf8("UserNameInput"));
        UserNameInput->setGeometry(QRect(80, 190, 591, 31));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", nullptr));
        passwordLabel->setText(QApplication::translate("login", "Password:", nullptr));
        userNameLabel->setText(QApplication::translate("login", "Username:", nullptr));
        LoginButton->setText(QApplication::translate("login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
