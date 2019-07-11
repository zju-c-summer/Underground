#include"smallMap.h"

smallMap::smallMap(QWidget *parent, mazeModel *maze):QWidget (parent), maze(maze){
	resize(320, 320);
    des_x = 10000; des_y = -1000;
    x = y = 0;
}

smallMap::~smallMap(){}

void smallMap::setModel(mazeModel *maze) {
	this->maze = maze;
}

void smallMap::paintEvent(QPaintEvent *event){
    QPixmap pixmap(size());
    //QPainter painter(&pixmap);
    QPainter painter(this);

    QTransform transform;

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
    dis = sqrt((double_t)(des_x - x) * (des_x - x) + (des_y - y) * (des_y - y));
    angle = asin((double_t)(des_y - y) / dis) * 180.0 / 3.1415926;
    std::cout << (des_y - y) / dis << std::endl;
    if(des_x - x < 0) angle = 180 - angle;
    std::cout << dis << " " << angle << std::endl;
    //painter.setWindow(QRect());
    transform.rotate(angle);
    //painter.translate(160, 160);
    painter.setWindow(-160, 160, 320, -320);
    painter.setTransform(transform, false);

    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    int cx;
    cx = (dis / 10) < 100 ? dis / 10 : 100;
    std::cout << cx << std::endl;
    painter.drawEllipse(cx - 5, -5, 10, 10);
    //painter.translate(160, 160);
}
