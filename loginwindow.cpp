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
                ui->statusLabel->setText(QString::fromStdString("Successful Login! Welcome"));
                ui->statusLabel->setVisible(true);
                hide();
                WelcomeWindow* welcomeWindow = new WelcomeWindow(this);
                welcomeWindow->show();

            }
            else
            {

                ui->statusLabel->setText(QString::fromStdString("Wrong Password!!"));
                ui->statusLabel->setVisible(true);
            }

            return;
        }
    }

    ui->statusLabel->setText(QString::fromStdString("Username not found! Register instead!"));
    ui->statusLabel->setVisible(true);
}


void LoginWindow::on_registerButton_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

