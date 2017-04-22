#include <QGraphicsView>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "bodygraphicsitem.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
    graphicsView_{},
    scene_{std::make_unique<QGraphicsScene>()},
    system_(this)
{

    ui_->setupUi(this);
    graphicsView_ = new QGraphicsView(scene_.get());
    graphicsView_->setObjectName(QStringLiteral("graphicsView"));

    ui_->horizontalLayout->addWidget(graphicsView_);
    system_.addBody(Body("Earth", 1000, 5, QVector2D(0, 0), QVector2D(0, 0)));
}

MainWindow::~MainWindow()
{
    delete ui_;
}

QGraphicsScene* MainWindow::scene() const
{
    return scene_.get();
}

System MainWindow::system() const
{
    return system_;
}
