#include "mainwindow.hpp"
#include <QApplication>
#include <iostream>

#include "body.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.system()->addBody(Body("Sol", 10000, 20, QVector2D(0, 0), QVector2D(1, 0)));
    w.system()->addBody(Body{"Venus", 100, 10, QVector2D{50, 0}, QVector2D{0, 1}});
    w.system()->addBody(Body{"Earth", 200, 12, QVector2D{100, 0}, QVector2D{0, -0.5}});
    w.system()->addBody(Body("Sol2", 10000, 20, QVector2D(-50, 50), QVector2D(0, 1)));

    w.show();

    return a.exec();
}
