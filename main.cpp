#include "mainwindow.h"

#include <QApplication>
// added a comment from my secondary account
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
