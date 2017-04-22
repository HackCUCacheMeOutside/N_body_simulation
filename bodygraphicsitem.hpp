#ifndef BODYGRAPHICSITEM_HPP
#define BODYGRAPHICSITEM_HPP

#include <memory>
#include <QGraphicsItem>

#include "body.hpp"

class BodyGraphicsItem : public QGraphicsItem
{
public:
    BodyGraphicsItem(std::shared_ptr<Body> body);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    const std::shared_ptr<Body> body_;
};

#endif // BODYGRAPHICSITEM_HPP
