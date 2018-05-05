#include "myitem.h"
#include <QPainter>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>

#include <QDrag>

#include <QMimeData>

#include <QApplication>

#include <QWidget>
MyItem::MyItem()
{
    setToolTip("Click and drag me!");  //提示
    setCursor(Qt::OpenHandCursor);    //改变光标形状
    //初始化随机颜色
    color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);
}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->drawEllipse(0, 0, 20, 20);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
        {
            //如果不是鼠标左键按下，则忽略该事件
            event->ignore();
            return;
        }
        //如果是鼠标左键按下，改变光标形状
        setCursor(Qt::ClosedHandCursor);

}
void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(QLineF(event->screenPos(),
            event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
    {
      //如果按下的点到现在的点的距离小于程序默认的拖动距离，表明没有拖动，则返回
        return;
    }
    //为event所在窗口部件新建拖动对象
    QDrag *drag = new QDrag(event->widget());
    //新建QMimeData对象，它用来存储拖动的数据
    QMimeData *mime = new QMimeData;
     //关联
    drag->setMimeData(mime);
    //放入颜色数据
    mime->setColorData(color);

    //新建QPixmap对象，它用来重新绘制圆形，在拖动时显示
    QPixmap pix(21,21);
    pix.fill(Qt::white);
    QPainter painter(&pix);
    paint(&painter, 0, 0);
    drag->setPixmap(pix);

    //我们让指针指向圆形的(10,15)点
    drag->setHotSpot(QPoint(10, 15));
    //开始拖动
    drag->exec();
    //改变光标形状
    setCursor(Qt::OpenHandCursor);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);    //改变光标形状
}
