#include "loginwindow.h"

#include <QApplication>
// added a comment from my secondary account
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}
