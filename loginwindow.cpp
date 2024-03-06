#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->statusLabel->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString enteredUsername = ui->usernameInput->text();
    QString enteredPassword = ui->passwordInput->text();

    for(int i=0; i<usersCount;i++)
    {
        if(enteredUsername == usernames[i])
        {
            if(enteredPassword == passwords[i])
            {
                int age = ages[i];
                hide();
                WelcomeWindow* welcomeWindow = new WelcomeWindow(enteredUsername, age, this);
                welcomeWindow->show();
            }
        }
    }

    ui->statusLabel->setVisible(true);
}


void LoginWindow::on_registerButton_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

