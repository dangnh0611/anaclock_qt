#include"class.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/clock.png"));
    app.setApplicationName("DDClock");
    QGraphicsScene scene;
    View view(&scene);
    view.setGeometry(0,0,200,200);
    //view.setFixedSize(700,700);
    view.setSceneRect(-220,-220,440,440);

    int hour=QTime::currentTime().hour();
    int min=QTime::currentTime().minute();
    int sec=QTime::currentTime().second();

    Face face;
    scene.addItem(&face);
    face.setZValue(1);

    SecondHand second_hand(QColor("#FF0000"),&face);//#66CC66
    second_hand.setRotation(6*sec);
    second_hand.setZValue(4);

    MinuteHand minute_hand(QColor("#242425"),&face);
    minute_hand.setRotation(6*(min+sec/60.0));
    minute_hand.setZValue(3);

    HourHand hour_hand(QColor("#242425"),&face);
    hour_hand.setRotation(30*(hour+min/60.0+sec/3600.0));
    hour_hand.setZValue(2);

    CenterPoint center(&face);
    center.setZValue(11);



    //QGraphicsEllipseItem* center_point=scene.addEllipse(-2,-2,4,4,Qt::NoPen,Qt::red);
  //  center_point->setZValue(10);



    QObject::connect(&view,SIGNAL(currentTimeChanged(int,int,int)),&second_hand,SLOT(rotateSecondHand(int,int,int)));
    QObject::connect(&view,SIGNAL(currentTimeChanged(int,int,int)),&minute_hand,SLOT(rotateMinuteHand(int,int,int)));
    QObject::connect(&view,SIGNAL(currentTimeChanged(int,int,int)),&hour_hand,SLOT(rotateHourHand(int,int,int)));
    view.startTimer(1000);
    view.resize(800,800);
    view.show();

    QSoundEffect effect;
    effect.setSource(QUrl("qrc:/sounds/tick.wav"));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.setVolume(1);
    effect.play();


    return app.exec();

}
