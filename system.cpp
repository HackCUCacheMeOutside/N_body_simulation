#include <algorithm>
#include <memory>

#include "mainwindow.hpp"
#include "system.hpp"
#include "body.hpp"
#include "bodygraphicsitem.hpp"

using namespace std;

System::System(MainWindow *mainWindow) : mainWindow_{mainWindow}
{
}

void System::addBody(Body body, const QColor& color)
{
    shared_ptr<Body> body_ptr = std::make_shared<Body>(body);
    bodies_.push_back(body_ptr);

    auto bodyItem = new BodyGraphicsItem{body_ptr, color};
    bodyItem->setPos(body_ptr->position().toPointF());
    mainWindow_->scene()->addItem(bodyItem);
}

void System::clearBody()
{
    bodies_.clear();
    mainWindow_->scene()->clear();
}

void System::update()
{
    for (auto i = bodies_.begin(), end = bodies_.end(); i != end; ++i) {
        (*i)->update(*this);
    }
}

std::string System::toString()
{
    std::string string;
    for (auto i = bodies_.begin(), end = bodies_.end(); i != end; ++i) {
        string += (*i)->toString() + "\n";
    }

    return string;
}

std::vector<std::shared_ptr<Body> > System::bodys() const
{
    return bodies_;
}

QVector2D System::centerOfMass()
{
    QVector2D centerOfMass{0, 0};
    double totalMass = 0;
    for (auto i = bodies_.begin(), end = bodies_.end(); i != end; ++i) {
        const auto mass = (*i)->mass();
        centerOfMass += mass * (*i)->position();
        totalMass += mass;
    }
    centerOfMass /= totalMass;
    return centerOfMass;
}
