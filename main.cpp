#include "mainwindow.hpp"
#include <QApplication>
#include <iostream>

#include "body.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //w.system()->addBody(Body("Sol2", 1000, 10, QVector2D(-50, 50), QVector2D(0, 1)));

    w.show();

    return a.exec();
}
