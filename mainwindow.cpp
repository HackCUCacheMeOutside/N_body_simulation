#include <QGraphicsView>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "bodygraphicsitem.hpp"

constexpr int frameRate = 1000 / 60;

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

    graphicsView_->setRenderHint(QPainter::Antialiasing);
    graphicsView_->setBackgroundBrush(QPixmap(":/background/background.jpg"));
    graphicsView_->setCacheMode(QGraphicsView::CacheBackground);
    graphicsView_->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graphicsView_->setDragMode(QGraphicsView::ScrollHandDrag);

    ui_->horizontalLayout->addWidget(graphicsView_);

    connect(&timer_, SIGNAL(timeout()), scene_.get(), SLOT(advance()));
    timer_.start(frameRate);

    connect(&update_timer_, SIGNAL(timeout()), this, SLOT(update()));
    update_timer_.start(frameRate);

    connect(ui_->addBodyButton, SIGNAL(clicked()), this, SLOT(addBodyFromGUI()));
    connect(ui_->resetButtom, SIGNAL(clicked()), this, SLOT(clearBody()));
    connect(ui_->pauseButton, SIGNAL(clicked()), this, SLOT(pauseButton()));
    connect(ui_->gotoPresetButton, SIGNAL(clicked()), this, SLOT(gotoPreset()));
    connect(ui_->timeStepInput, SIGNAL(valueChanged(int)), this, SLOT(changeDelta(int)));
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

void MainWindow::addBodyFromGUI()
{
    std::string name = ui_->NameInput->text().toStdString();
    double mass = ui_->massInput->value();
    int radius = ui_->radiusInput->value();

    double x = ui_->positionXInput->value();
    double y = ui_->positionYInput->value();

    double dx = ui_->velocityXInput->value();
    double dy = ui_->velocityYInput->value();

    auto colorText = ui_->ColorInput->currentText();
    QColor color;
    if (colorText == "White") {
        color = Qt::white;
    } else if  (colorText == "Blue") {
        color = Qt::blue;
    } else if  (colorText == "Red") {
        color = Qt::red;
    } else if  (colorText == "Yellow") {
        color = Qt::yellow;
    } else if  (colorText == "Orange") {
        color = QColor{255, 153, 0};
    } else if  (colorText == "Purple") {
        color = QColor{128, 0, 128};
    } else if  (colorText == "Green") {
        color = Qt::green;
    }

    system_->addBody(Body(name, mass, radius, QVector2D(x, y), QVector2D(dx, dy)), color);
}

void MainWindow::clearBody()
{
    system_->clearBody();
}

void MainWindow::changeDelta(int newDelta)
{
    system_->setDelta(newDelta);
}

void MainWindow::pauseButton()
{
    if (is_pause_) {
        update_timer_.start(frameRate);

        ui_->pauseButton->setText("Pause");
        is_pause_ = false;
    } else {
        update_timer_.stop();

        ui_->pauseButton->setText("Continue");
        is_pause_ = true;
    }
}

void MainWindow::gotoPreset()
{
    system_->clearBody();

    auto presetText = ui_->PresetsInput->currentText();

    if (presetText == "Solar System") {
        system_->addBody(Body("Sol", 10000, 20, QVector2D(0, 0), QVector2D(0, 0)), Qt::red);
        system_->addBody(Body{"Mercury", 20, 6, QVector2D{52, 0}, QVector2D{0, 10}}, Qt::blue);
        system_->addBody(Body{"Venus", 30, 7, QVector2D{-97, 0}, QVector2D{0, -10}}, Qt::yellow);
        system_->addBody(Body{"Earth", 40, 8, QVector2D{134, 0}, QVector2D{0, 10}}, Qt::blue);
        system_->addBody(Body{"Moon", 1, 5, QVector2D{72.7f, 0}, QVector2D{0, 10}}, Qt::white);
        system_->addBody(Body{"Mars", 30, 7, QVector2D{90, 0}, QVector2D{0, 10}}, Qt::red);
        //system_->addBody(Body{"Jupitor", 200, 14, QVector2D{120, 0}, QVector2D{0, 10}}, Qt::red);
        //system_->addBody(Body{"Saturn", 150, 12, QVector2D{140, 0}, QVector2D{0, 10}}, Qt::yellow);
        //system_->addBody(Body{"Uranus", 100, 10, QVector2D{170, 0}, QVector2D{0, 10}}, Qt::cyan);
        //system_->addBody(Body{"Neptune", 100, 10, QVector2D{190, 0}, QVector2D{0, 10}}, Qt::blue);
    } else if  (presetText == "Trappist-1") {
        system_->addBody(Body("Trappist-1", 10000, 20, QVector2D(0, 0), QVector2D(0, 0)), Qt::red);
        system_->addBody(Body{"Trappist-b", 31.875, 6, QVector2D{50, 0}, QVector2D{0, 10}}, Qt::blue);
        system_->addBody(Body{"Trappist-c", 48, 7, QVector2D{-85, 0}, QVector2D{0, -10}}, Qt::yellow);
        system_->addBody(Body{"Trappist-d", 15, 8, QVector2D{115, 0}, QVector2D{0, 9}}, Qt::blue);
        system_->addBody(Body("Trappist-e", 23.25, 20, QVector2D(-140.27f, 0), QVector2D(0, -9)), Qt::red);
        system_->addBody(Body{"Trappist-f", 25.5, 6, QVector2D{182.18f, 0}, QVector2D{0, 8}}, Qt::blue);
        system_->addBody(Body{"Trappist-g", 50, 7, QVector2D{-220, 0}, QVector2D{0, -8}}, Qt::yellow);
    }else if  (presetText == "Apocalypse - Blackhole") {
        system_->addBody(Body("Sol", 10000, 20, QVector2D(0, 0), QVector2D(0, 0)), Qt::red);
        system_->addBody(Body{"Mercury", 20, 6, QVector2D{52, 0}, QVector2D{0, 10}}, Qt::blue);
        system_->addBody(Body{"Venus", 30, 7, QVector2D{-97, 0}, QVector2D{0, -10}}, Qt::yellow);
        system_->addBody(Body{"Earth", 40, 8, QVector2D{134, 0}, QVector2D{0, 10}}, Qt::blue);
        system_->addBody(Body{"Black Hole", 40000, 20, QVector2D{500, 500}, QVector2D{-10, -8}}, Qt::white);
    }else if  (presetText == "Apocalypse - Asteroid Collisions") {
        system_->addBody(Body("Sol", 10000, 20, QVector2D(0, 0), QVector2D(0, 0)), Qt::red);
        system_->addBody(Body{"Mercury", 20, 6, QVector2D{52, 0}, QVector2D{0, 12}}, Qt::blue);
        system_->addBody(Body{"Venus", 30, 7, QVector2D{-97, 0}, QVector2D{0, -12}}, Qt::yellow);
        system_->addBody(Body{"Earth", 40, 8, QVector2D{134, 0}, QVector2D{0, 10}}, Qt::blue);
        system_->addBody(Body{"Asteroid #1", 20, 20, QVector2D{-373, -380}, QVector2D{16, 13}}, Qt::white);
        system_->addBody(Body{"Asteroid #2", 25, 20, QVector2D{-320, -3700}, QVector2D{14, 14}}, Qt::white);
        system_->addBody(Body{"Asteroid #3", 25, 20, QVector2D{-320, -375}, QVector2D{13, 14}}, Qt::white);
        system_->addBody(Body{"Asteroid #4", 25, 20, QVector2D{-380, -360}, QVector2D{13, 12}}, Qt::white);
        system_->addBody(Body{"Asteroid #5", 23, 20, QVector2D{-340, -400}, QVector2D{12, 11}}, Qt::white);
        system_->addBody(Body{"Asteroid #6", 25, 20, QVector2D{-400, -380}, QVector2D{13, 11}}, Qt::white);
}}
