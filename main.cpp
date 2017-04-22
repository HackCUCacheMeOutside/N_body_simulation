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

    w.system().addBody(Body{"earth", 0, 0, QVector2D{0, 0}, QVector2D{0, 0}});

    return a.exec();
}
