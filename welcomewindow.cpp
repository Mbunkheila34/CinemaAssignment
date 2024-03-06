#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    ui->helloLabel->setText(QString("Hello ") + username + QString(" ") + QString::number(age));
    QPixmap pixmap("C:\\Users\\Owner\\Documents\\CinemaAssignment\\welcome.png");
    if (pixmap.isNull()) {
        qDebug() << "Error: Unable to load image";
    }

    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();
    ui->imageLabel->setPixmap(pixmap.scaled(w,h));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logoutButton_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow();
    loginWindow->show();
}

