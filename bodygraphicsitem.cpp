#include <QPainter>

#include "bodygraphicsitem.hpp"

BodyGraphicsItem::BodyGraphicsItem(const std::shared_ptr<Body>& body,
                                   const QColor& color)
    : body_{body},
      color_{color}
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
    auto radius = static_cast<int>(body_->radius());
    path.addRect(-radius, -radius, radius, radius);
    return path;
}

void BodyGraphicsItem::paint(QPainter* painter,
                             const QStyleOptionGraphicsItem* option,
                             QWidget* widget)
{
    auto radius = static_cast<int>(body_->radius());

    painter->translate(radius / 2, radius / 2);
    painter->setBrush(color_);
    painter->drawEllipse(-radius, -radius, radius, radius);
}

void BodyGraphicsItem::advance(int step)
{
    if (!step)
        return;

    setPos(body_->position().toPointF());
}
