#include <QPainter>

#include "bodygraphicsitem.hpp"

BodyGraphicsItem::BodyGraphicsItem(std::shared_ptr<Body> body)
    : body_{body}
{

}

QRectF BodyGraphicsItem::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath BodyGraphicsItem::shape() const
{
    QPainterPath path;
    path.addRect(-10, -10, 10, 10);
    return path;
}

void BodyGraphicsItem::paint(QPainter* painter,
                             const QStyleOptionGraphicsItem* option,
                             QWidget* widget)
{
    auto radius = static_cast<int>(body_->radius());

    painter->translate(radius / 2, radius / 2);
    painter->setBrush(Qt::red);
    painter->drawEllipse(-radius, -radius, radius, radius);
}

void BodyGraphicsItem::advance(int step)
{
    if (!step)
        return;

    setPos(body_->position().toPointF());
}
