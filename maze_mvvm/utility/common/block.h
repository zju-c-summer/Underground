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
    void set_type(int typ);//设置单元格类型，0为墙，1为通路，为出口，3为入口
   // void set_color(QColor colo){color=colo;}
    void set_block_size(int size);//设置单元格大小
    int get_block_size();//获得单元格大小
    int get_type();//获得单元格类型
  //  QColor get_color(){return color;}
    void set_x(int _x);//设置单元格x坐标
    void set_y(int _y);//设置单元格y坐标
    int get_x();//获得单元格x坐标
    int get_y();//获得单元格y坐标

};

#endif // BLOCK_H
