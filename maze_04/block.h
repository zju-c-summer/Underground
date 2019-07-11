#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
class block{
private:
    int type;//type==1 则为通路，为0则是墙,2为出口,3为入口,4为玩家
  //  QColor color;
    int block_size;
    int x;
    int y;
public:
    block();
    ~block(){std::cout<<"~block"<<std::endl;}
    void set_type(int typ);
   // void set_color(QColor colo){color=colo;}
    void set_block_size(int size);
    int get_block_size();
    int get_type();
  //  QColor get_color(){return color;}
    void set_x(int _x);
    void set_y(int _y);
    int get_x();
    int get_y();

};

#endif // BLOCK_H
