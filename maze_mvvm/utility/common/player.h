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
    void set_x(double _x);//设置玩家x坐标
    void set_y(double _y);//设置玩家y坐标
 //   QColor get_color();
    double get_x();//获得玩家x坐标
    double get_y();//获得玩家y坐标
    void set_direction(int i);//设置玩家移动方向，0左1右2上3下
    int get_direction();//获得玩家移动方向
    int get_size();//设置玩家大小
    void moveR();//向右移动指定长度
    void moveL();//向左移动指定长度
    void moveU();//向上移动指定长度
    void moveD();//向下移动指定长度
    void set_step(double _step);//设置移动长度大小
    double get_step();//获得移动长度大小
};

#endif // PLAYER_H
