#include "mainwindow.hpp"
#include <QApplication>
#include <iostream>

#include "body.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Body earth("Earth", 1000, 5, QVector2D(0, 0), QVector2D(0, 0));
    cout << earth.toString() << "\n";
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
