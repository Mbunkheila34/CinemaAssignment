#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "users.h"
#include "welcomewindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->dobStatusLabel->setVisible(false);
    ui->registerStatusLabel->setVisible(false);
    ui->rePasswordStatusLabel->setVisible(false);
    ui->usernameStatusLabel->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerButton_clicked()
{
    ui->dobStatusLabel->setVisible(false);
    ui->registerStatusLabel->setVisible(false);
    ui->rePasswordStatusLabel->setVisible(false);
    ui->usernameStatusLabel->setVisible(false);
    bool complete = true;

    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();
    QString rePassword = ui->rePasswordInput->text();

    for(int i=0;i<usersCount;i++)
    {
        if(username == usernames[i])
        {
            complete = false;
            ui->usernameStatusLabel->setVisible(true);
        }
    }

    if(password != rePassword)
    {
        complete = false;
        ui->rePasswordStatusLabel->setVisible(true);
    }

    int DOB_year = ui->yearInput->text().toInt();
    int DOB_month = ui->monthComboBox->currentText().toInt();
    int DOB_day = ui->dayInput->text().toInt();
    int age = 2024 - DOB_year;

    if(age < 12)
    {
        complete = false;
        ui->dobStatusLabel->setVisible(true);
    }

    if(!(ui->maleRadioButton->isChecked() || ui->femaleRadioButton->isChecked()))
    {
        complete = false;
        ui->registerStatusLabel->setVisible(true);
    }

    if(!(ui->userRadioButton->isChecked() || ui->adminRadioButton->isChecked()))
    {
        complete = false;
        ui->registerStatusLabel->setVisible(true);
    }

    if(!( ui->actionCheckBox->isChecked() ||
          ui->comedyCheckBox->isChecked() ||
          ui->drameCheckBox->isChecked() ||
          ui->horrorCheckBox->isChecked() ||
          ui->otherCheckBox->isChecked() ||
          ui->romanceCheckBox->isChecked()))
    {
        complete = false;
        ui->registerStatusLabel->setVisible(true);
    }

    if(complete)
    {
        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = age;
        usersCount++;

        hide();
        WelcomeWindow* welcomeWindow = new WelcomeWindow(username, age, this);
        welcomeWindow->show();
    }

}

