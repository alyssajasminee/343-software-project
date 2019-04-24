#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
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
        login->setObjectName(QStringLiteral("login"));
        login->resize(760, 431);
        passwordLabel = new QLabel(login);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(80, 230, 141, 16));
        PasswordInput = new QLineEdit(login);
        PasswordInput->setObjectName(QStringLiteral("PasswordInput"));
        PasswordInput->setGeometry(QRect(80, 250, 591, 31));
        PasswordInput->setEchoMode(QLineEdit::Password);
        userNameLabel = new QLabel(login);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setGeometry(QRect(80, 170, 141, 16));
        LoginButton = new QPushButton(login);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        login->setObjectName(QString::fromUtf8("login"));
        login->resize(760, 431);
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
        LoginButton->setGeometry(QRect(510, 300, 75, 21));
        QFont font;
        font.setPointSize(7);
        LoginButton->setFont(font);
        UserNameInput = new QLineEdit(login);
        UserNameInput->setObjectName(QStringLiteral("UserNameInput"));
        UserNameInput->setObjectName(QString::fromUtf8("UserNameInput"));
        UserNameInput->setGeometry(QRect(80, 190, 591, 31));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("login", "Password:", Q_NULLPTR));
        userNameLabel->setText(QApplication::translate("login", "Username:", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("login", "Login", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
