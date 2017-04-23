#include <QGraphicsView>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "bodygraphicsitem.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow),
    graphicsView_{},
    scene_{std::make_unique<QGraphicsScene>()},
    system_(std::make_unique<System>(this)),
    timer_{},
    update_timer_{}
{
    scene_->setSceneRect(-300, -300, 600, 600);

    ui_->setupUi(this);
    graphicsView_ = new QGraphicsView(scene_.get());
    graphicsView_->setObjectName(QStringLiteral("graphicsView"));

    ui_->horizontalLayout->addWidget(graphicsView_);

    connect(&timer_, SIGNAL(timeout()), scene_.get(), SLOT(advance()));
    timer_.start(1000 / 33);

    connect(&update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    update_timer_.start(1000 * delta);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

QGraphicsScene* MainWindow::scene() const
{
    return scene_.get();
}

System* MainWindow::system() const
{
    return system_.get();
}

void MainWindow::update()
{
    system_->update();
}
