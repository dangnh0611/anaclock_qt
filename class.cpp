#include"class.h"


View::View(QGraphicsScene *scene, QWidget *parent):QGraphicsView(scene,parent){}
void View::timerEvent(QTimerEvent* event){
    Q_UNUSED(event);
    int hour=QTime::currentTime().hour();
    int min=QTime::currentTime().minute();
    int sec=QTime::currentTime().second();
    emit currentTimeChanged(hour,min,sec);
}
void View::resizeEvent(QResizeEvent* event){
    Q_UNUSED(event);
    fitInView(sceneRect());
}

Face::Face(QGraphicsItem *parent):QGraphicsItem (parent){}


QRectF Face::boundingRect() const
{
    return QRectF(-220,-220,440,440);
}

void Face::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setRenderHint(QPainter::Antialiasing);
    QPixmap pix(":/images/face.png");
    painter->rotate(-0.7);
    painter->setOpacity(1);
    painter->drawPixmap(QRect(-216,-215,440,440),pix);
    painter->rotate(0.7);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setFont(QFont("Times",25));
    painter->setBrush(QColor("#444348"));


    for(int i=0;i<12;i++){
            painter->setPen(Qt::NoPen);
            painter->drawConvexPolygon(points,4);
    painter->rotate(30);
    }

    painter->setOpacity(0.17);
    painter->drawPixmap(QRect(-50,-50,100,100),QPixmap(":/images/icon.png"));
    painter->setOpacity(0.43);
    painter->setPen(QPen(QColor(Qt::black),1));
    painter->drawText(QRectF(-45,27,100,30),Qt::AlignCenter,"HĐ");
}


SecondHand::SecondHand(const QBrush& brush_,QGraphicsItem *parent):QGraphicsObject (parent),brush(brush_){
    animation = new QPropertyAnimation(this, "rotation");
    animation->setEasingCurve(QEasingCurve::OutElastic);
    animation->setDuration(200);
}

QRectF SecondHand::boundingRect() const
{
    return QRectF(-5,-155,10,185);
}

void SecondHand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    //painter->drawEllipse(-4,-4,10,10);
    painter->drawConvexPolygon(points,4);
    painter->setBrush(QColor("#242425"));
    painter->drawEllipse(-11,-11,22,22);
}


void SecondHand::rotateSecondHand(int hour,int min,int sec){
    Q_UNUSED(hour)
    Q_UNUSED(min)
    animation->setStartValue(6*(sec-1));
    animation->setEndValue(6*sec);
    animation->start();
}






MinuteHand::MinuteHand(const QBrush& brush_,QGraphicsItem *parent):QGraphicsObject (parent),brush(brush_){}

QRectF MinuteHand::boundingRect() const
{
    return QRectF(-9,-150,18,159);
}

void MinuteHand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->drawEllipse(-9,-9,18,18);
    painter->drawConvexPolygon(points,5);
    painter->setBrush(QColor("#99FF66"));
    painter->drawRect(QRectF(-1.7,-142,3.4,126));
}


void MinuteHand::rotateMinuteHand(int hour,int min,int sec){
    Q_UNUSED(hour)
    this->setRotation(6*(min+sec/60.0));
}



HourHand::HourHand(const QBrush& brush_,QGraphicsItem *parent):QGraphicsObject (parent),brush(brush_){}

QRectF HourHand::boundingRect() const
{
    return QRectF(-14,-120,28,129);
}

void HourHand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);
    painter->drawEllipse(-11,-11,22,22);
    painter->drawConvexPolygon(points,5);
    painter->setBrush(QColor("#99FF66"));// #DBE794
    painter->drawRect(QRectF(-3.4,-85,6.8,57));
}

void HourHand::rotateHourHand(int hour,int min,int sec){
    this->setRotation(30*(hour+min/60.0+sec/3600.0));
}



CenterPoint::CenterPoint(QGraphicsItem *parent):QGraphicsItem (parent){}

QRectF CenterPoint::boundingRect() const
{
    return QRectF();
}

void CenterPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setOpacity(0.2);
    painter->drawPixmap(QRect(-20,-20,40,40),QPixmap(":/images/center"));
}
