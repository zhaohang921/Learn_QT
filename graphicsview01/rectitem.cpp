#include "rectitem.h"
#include <QPainter>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>

#include <QDrag>

#include <QMimeData>

#include <QApplication>

#include <QWidget>


RectItem::RectItem()
{
    setAcceptDrops(true);  //设置接收拖放
    color = QColor(Qt::lightGray);
}

QRectF RectItem::boundingRect() const
{
     return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *,
                     QWidget *)
{
    //如果其上有拖动，颜色变亮
    painter->setBrush(dragOver ? color.light(130) : color);
    painter->drawRect(0,0,50,50);
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasColor()) //如果拖动的数据中有颜色数据，便接收
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
    else event->setAccepted(false);
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasColor())
       //我们通过类型转换来获得颜色
        color = qvariant_cast(event->mimeData()->colorData());
     update();
}


