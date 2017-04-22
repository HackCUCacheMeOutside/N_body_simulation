#include "mainwindow.hpp"
#include <QApplication>
#include <iostream>

#include "body.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.system().addBody(Body("Sol", 10000, 20, QVector2D(0, 0), QVector2D(0, 0)));
    w.system().addBody(Body{"Venus", 100, 10, QVector2D{50, 0}, QVector2D{0, 0}});
    w.system().addBody(Body{"Earth", 200, 12, QVector2D{100, 0}, QVector2D{0, 0}});

    return a.exec();
}
