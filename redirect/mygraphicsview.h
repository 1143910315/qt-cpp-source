#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QObject>

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget *parent = nullptr);
    MyGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);
    MyGraphicsView *setBackgroudColor(int red,int green,int blue);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    QPoint startPos;
    int red;
    int green;
    int blue;
};

#endif // MYGRAPHICSVIEW_H
