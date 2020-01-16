#ifndef MYITEM_H
#define MYITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>

class MyItem : public QGraphicsItem
{
public:
    MyItem();

    QRectF boundingRect() const override;

    // overriding paint()
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget) override;

    // item state
    bool pressed;

private:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MYITEM_H
