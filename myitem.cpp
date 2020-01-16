#include "myitem.h"

MyItem::MyItem()
{
    pressed = false;
    setFlag(ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF MyItem::boundingRect() const
{
    // outer most edges
    return QRectF(0,0,100,100);
}

void MyItem::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    QRectF rec = boundingRect();    
    QBrush brush;

    if (pressed) {
        QPen pen(Qt::red,3);
        painter->setPen(pen);
        painter->drawRect(rec);
    } else {
        QPen pen(Qt::green,3);
        painter->setPen(pen);
        painter->drawEllipse(rec);
    }
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
    qDebug() << "after pressing mouse key x=" << x() << ", y=" << y();
    /**/
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
    qDebug() << "after releasing mouse key x=" << x() << ", y=" << y();
    /**/
}

void MyItem::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "you pressed a key";
    if (event->key() == Qt::Key_Left) {
        setPos(x()-10,y());
    } else if (event->key() == Qt::Key_Right) {
        setPos(x()+10,y());
    } else if (event->key() == Qt::Key_Down) {
        setPos(x(),y()+10);
    } else if (event->key() == Qt::Key_Up) {
        setPos(x(),y()-10);
    }
    qDebug() << "after pressing key x=" << x() << ", y=" << y();
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseMoveEvent(event);
    qDebug() << "after moving mouse key x=" << x() << ", y=" << y();

}/**/
