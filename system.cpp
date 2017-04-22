#include <algorithm>
#include <memory>

#include "mainwindow.hpp"
#include "system.hpp"
#include "body.hpp"
#include "bodygraphicsitem.hpp"

System::System(MainWindow *mainWindow) : mainWindow_{mainWindow}
{
}

void System::addBody(Body body)
{
    std::shared_ptr<Body> body_ptr = std::make_shared<Body>(std::move(body));
    bodys_.push_back(body_ptr);

    auto bodyItem = new BodyGraphicsItem{body_ptr};
    bodyItem->setPos(body_ptr->postion().toPointF());
    mainWindow_->scene()->addItem(bodyItem);

}

void System::update()
{
    for (auto i = bodys_.begin(), end = bodys_.end(); i != end; ++i) {
        (*i)->update(*this);
    }
}

std::string System::toString()
{
    std::string string;
    for (auto i = bodys_.begin(), end = bodys_.end(); i != end; ++i) {
        string += (*i)->toString() + "\n";
    }

    return string;
}
