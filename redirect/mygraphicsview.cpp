#include "mygraphicsview.h"
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>

MyGraphicsView::MyGraphicsView(QWidget *parent):QGraphicsView(parent)
{

}

MyGraphicsView::MyGraphicsView(QGraphicsScene *scene, QWidget *parent):QGraphicsView (scene,parent)
{

}

MyGraphicsView *MyGraphicsView::setBackgroudColor(int red, int green, int blue)
{
    this->setStyleSheet(QString::asprintf("background: rgb(%d,%d,%d)",this->red=red,this->green=green,this->blue=blue));
    return this;
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
    startPos=event->pos();
    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    this->viewport()->setCursor(Qt::PointingHandCursor);
    if(event->buttons()&Qt::LeftButton){
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance() && !this->rect().contains(event->pos())){
            QMimeData *mimeData = new QMimeData;
            mimeData->setColorData(QColor(red,green,blue));
            QDrag* drag = new QDrag(this);
            drag->setMimeData(mimeData);
            drag->setHotSpot(event->pos());
            drag->exec(Qt::CopyAction, Qt::CopyAction);
        }
    }
    QGraphicsView::mouseMoveEvent(event);
}


