#include "mainwindow.hpp"
#include <QApplication>
#include <iostream>

#include "body.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.system()->addBody(Body("Sol", 10000, 20, QVector2D(0, 0), QVector2D(0, 0)), Qt::red);
    w.system()->addBody(Body{"Mercury", 20, 6, QVector2D{40, 0}, QVector2D{0, 10}}, Qt::blue);
    w.system()->addBody(Body{"Venus", 30, 7, QVector2D{50, 0}, QVector2D{0, 10}}, Qt::yellow);
    w.system()->addBody(Body{"Earth", 40, 8, QVector2D{60, 0}, QVector2D{0, 10}}, Qt::blue);
    w.system()->addBody(Body{"Mars", 30, 7, QVector2D{75, 0}, QVector2D{0, 10}}, Qt::red);

    //w.system()->addBody(Body("Sol2", 1000, 10, QVector2D(-50, 50), QVector2D(0, 1)));

    w.show();

    return a.exec();
}
