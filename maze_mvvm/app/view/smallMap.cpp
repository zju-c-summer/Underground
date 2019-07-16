#include"smallMap.h"

smallMap::smallMap(QWidget *parent):QWidget (parent){
    setGeometry(50, 50, 320, 320);
    update_view_notification = std::static_pointer_cast<Notification,smallMapNotification>
            (std::shared_ptr<smallMapNotification>(new smallMapNotification));
    std::static_pointer_cast<smallMapNotification, Notification>(update_view_notification)->setView(this);
}

smallMap::~smallMap(){}

void smallMap::paintEvent(QPaintEvent *event){
    QPixmap pixmap(size());
    //QPainter painter(&pixmap);
    QPainter painter(this);

    QTransform transform;
    //updatePos();
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::ConicalGradientPattern);
    //QRadialGradient radialGradient(10 + 200 , 10 + 200, 150, 150, 110);
    //radialGradient.setColorAt(0, Qt::gray);
    //radialGradient.setColorAt(0.2, Qt::black);
    //radialGradient.setColorAt(0.8, Qt::gray);
    QConicalGradient conicalGradient(150, 150, -45);
    conicalGradient.setColorAt(0, Qt::gray);
    conicalGradient.setColorAt(0.3, Qt::black);
    //conicalGradient.setColorAt(1.0, Qt::yellow);
    painter.setBrush(QBrush(conicalGradient));
    painter.drawEllipse(40, 40, 240, 240);
    painter.save();
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.drawEllipse(50 + 10, 50 + 10, 200, 200);

    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawEllipse(155, 155, 10, 10);

    double_t angle, dis;
    int x = (*des_x + 1) * BLOCK_SIZE;
    int y = (*des_y + 1) * BLOCK_SIZE;
    dis = sqrt((double_t)(x - man->get_x()) * (x - man->get_x()) + (y - man->get_y()) * (y - man->get_y()));
    angle = asin((double_t)(y - man->get_y()) / dis) * 180.0 / 3.1415926;
    if(x - man->get_x() < 0) angle = 180 - angle;
    transform.rotate(-angle);
    painter.setWindow(-160, 160, 320, -320);
    painter.setTransform(transform, false);

    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    int cx;
    cx = (dis / 10) < 100 ? dis / 10 : 100;
    painter.drawEllipse(cx - 5, -5, 10, 10);
}

void smallMap::bindDesc(std::shared_ptr<int> x, std::shared_ptr<int> y){
    des_x = x; des_y = y;
}

void smallMap::bindPlayer(std::shared_ptr<player> man){
    this->man = man;
}

std::shared_ptr<Notification> smallMap::getNotification(){
    return update_view_notification;
}

