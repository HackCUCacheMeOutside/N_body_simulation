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
        system_->addBody(Body{"Mercury", 20, 6, QVector2D{50, 0}, QVector2D{0, 10}}, Qt::blue);
        system_->addBody(Body{"Venus", 30, 7, QVector2D{60, 0}, QVector2D{0, 10}}, Qt::yellow);
        system_->addBody(Body{"Earth", 40, 8, QVector2D{70, 0}, QVector2D{0, 10}}, Qt::blue);
        //system_->addBody(Body{"Moon", 1, 5, QVector2D{72.7, 0}, QVector2D{0, 10}}, Qt::white);
        system_->addBody(Body{"Mars", 30, 7, QVector2D{90, 0}, QVector2D{0, 10}}, Qt::red);
        system_->addBody(Body{"Jupitor", 200, 14, QVector2D{120, 0}, QVector2D{0, 10}}, Qt::red);
        system_->addBody(Body{"Saturn", 150, 12, QVector2D{140, 0}, QVector2D{0, 10}}, Qt::yellow);
        system_->addBody(Body{"Uranus", 100, 10, QVector2D{170, 0}, QVector2D{0, 10}}, Qt::cyan);
        system_->addBody(Body{"Neptune", 100, 10, QVector2D{190, 0}, QVector2D{0, 10}}, Qt::blue);
    } else if  (presetText == "Binary Star, Planet") {
        //color = Qt::blue;
    }

}
