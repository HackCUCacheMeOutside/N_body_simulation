#include <QGraphicsView>
#include <QTimer>

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
    scene_->setSceneRect(-300, -300, 600, 600);

    ui_->setupUi(this);
    graphicsView_ = new QGraphicsView(scene_.get());
    graphicsView_->setObjectName(QStringLiteral("graphicsView"));

    ui_->horizontalLayout->addWidget(graphicsView_);

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), scene_.get(), SLOT(advance()));
    timer.start(1000 / 33);

    QTimer updates_timer;
    QObject::connect(&updates_timer, SIGNAL(timeout()), scene_.get(), SLOT(update()));
    updates_timer.start(static_cast<int>(1000 * delta));
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

void MainWindow::update()
{
    system_.update();
}
