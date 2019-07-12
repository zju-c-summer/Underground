#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QColor>
#include "common_value.h"

class player{
private:
    double x,y;//坐标，需要double
    int direction;//0为左，1为右，2为上，3为下
  //  QColor color;
    int size;
    double step;
public:
    player();
    player(double _x, double _y);
    ~player();
    void set_x(double _x);
    void set_y(double _y);
 //   QColor get_color();
    double get_x();
    double get_y();
    void set_direction(int i);
    int get_direction();
    int get_size();
    void moveR();
    void moveL();
    void moveU();
    void moveD();
    void set_step(double _step);
    double get_step();
};

#endif // PLAYER_H
