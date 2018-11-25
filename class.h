#ifndef CLASS_H
#define CLASS_H
#include<QSoundEffect>
#include<QWidget>
#include<QApplication>
#include <QGraphicsObject>
#include<QPropertyAnimation>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QTime>
#include<QPainter>
#include<QGraphicsEllipseItem>
#include<QIcon>
    //VIEW CLASS
class View:public QGraphicsView{
    Q_OBJECT
public:
    View(QGraphicsScene *scene, QWidget *parent = nullptr);
signals:
    void currentTimeChanged(int,int,int);
protected:
    void timerEvent(QTimerEvent*) override;
    void resizeEvent(QResizeEvent* event) override;
};

    //CLOCK_FACE CLASS
class Face:public QGraphicsItem{
public:
    Face(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
private:
    const QPointF points[4] = {
        QPointF(-4,-83),
        QPointF(4,-83),
        QPointF(2.5,-95),
        QPointF(-2.5,-95)
    };

    };



    //SECOND_HAND CLASS
class SecondHand:public QGraphicsObject{
    Q_OBJECT
public:
    SecondHand(const QBrush&,QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
public slots:
    void rotateSecondHand(int,int,int);
private:
    QBrush brush;
    QPropertyAnimation* animation;
    const QPointF points[4] = {
        QPointF(-1.8,30),
        QPointF(1.8,30),
        QPointF(0.9,-155),
        QPointF(-0.9,-155)
    };

};

    //MINUTE_HAND CLASS
class MinuteHand:public QGraphicsObject{
    Q_OBJECT
public:
    MinuteHand(const QBrush&,QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
public slots:
    void rotateMinuteHand(int,int,int);
private:
    QBrush brush;
    const QPointF points[5] = {
        QPointF(-4.2,0),
        QPointF(4.2,0),
        QPointF(4.2,-143),
        QPointF(0,-150),
        QPointF(-4.2,-143)
    };


};


//HOUR_HAND CLASS
class HourHand:public QGraphicsObject{
Q_OBJECT
public:
    HourHand(const QBrush&,QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
public slots:
    void rotateHourHand(int,int,int);
private:
    QBrush brush;
    const QPointF points[5] = {
        QPointF(-6.4,0),
        QPointF(6.4,0),
        QPointF(6.4,-87),
        QPointF(0,-94),
        QPointF(-6.4,-87)
    };


};
class CenterPoint:public QGraphicsItem{
public:
    CenterPoint(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
};




































#endif // CLASS_H
