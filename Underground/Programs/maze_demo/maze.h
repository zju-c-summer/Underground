#ifndef MAZE_H
#define MAZE_H
#include <QGraphicsItem>
//#include <iostream>
#include <vector>
#include <qpainter.h>
#include <QPaintEvent>
#include "prim.h"
#include "commentvalue.h"
using namespace std;

class block{
private:
    int type;//type==1 则为通路，为0则是墙,2为出口,3为入口,4为玩家
    QColor color;
    int block_size;
    int x;
    int y;
    int visited;
public:
    block():type(0),color(0,0,0),block_size(BLOCK_SIZE),x(0),y(0),visited(0){}
    void set_type(int typ){type=typ;}
    void set_color(QColor colo){color=colo;}
    void set_block_size(int size){block_size=size;}
    int get_block_size(){return block_size;}
    int get_type(){return type;}
    QColor get_color(){return color;}
    void set_x(int _x){x=_x;}
    void set_y(int _y){y=_y;}
    int get_x(){return x;}
    int get_y(){return y;}
    int get_visited(){return visited;}
    void set_visited(int i){visited=i;}

};

class player{
private:
    double x,y;//坐标，需要double
    int direction;//0为左，1为右，2为上，3为下
    QColor color;
    int size;
    double step;
public:
    player():x(0),y(0),direction(3),size(PLAYER_SIZE),color(0,0,255),step(PLAYER_SIZE/4){}
    player(double _x, double _y):x(_x),y(_y),direction(3),size(PLAYER_SIZE),color(0,0,255),step(PLAYER_SIZE/4){}
    ~player(){}
    void set_x(double _x){x=_x;}
    void set_y(double _y){y=_y;}
    QColor get_color(){return color;}
    double get_x(){return x;}
    double get_y(){return y;}
    void set_direction(int i){direction = i;}
    int get_direction(){return direction;}
    int get_size(){return size;}
    void moveR(){x+=step;}
    void moveL(){x-=step;}
    void moveU(){y-=step;}
    void moveD(){y+=step;}
    void set_step(double _step){step=_step;}
    double get_step(){return step;}
};

class mazeModel : public QGraphicsItem{
private:
    unsigned int row_size;
    unsigned int col_size;
    vector< vector< block > >  maze;
    player man;
    player monster;
public:
    unsigned int get_row_size(){return row_size;}
    unsigned int get_col_size(){return col_size;}
    player & get_man();
    player & get_monster();
    void moveMan(int _direction);
    void init();
    block & get_block(int i,int j){return maze[i][j];}
    mazeModel();
    void set_block(int row,int col,int type,QColor color,int size);
    QRectF boundingRect()const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void paintEvent(QPaintEvent * event);
    vector< vector< block > > & get_maze(){return maze;};
    void generateMaze();
protected:

    void advance(int step);

};
#endif
