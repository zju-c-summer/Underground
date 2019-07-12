#include "player.h"
player::player():x(0),y(0),direction(3),size(PLAYER_SIZE),step(PLAYER_SIZE/4){}
player::player(double _x, double _y):x(_x),y(_y),direction(3),size(PLAYER_SIZE),step(PLAYER_SIZE/4){}
player::~player(){}
void player::set_x(double _x){x=_x;}
void player::set_y(double _y){y=_y;}
//QColor player::get_color(){return color;}
double player::get_x(){return x;}
double player::get_y(){return y;}
void player::set_direction(int i){direction = i;}
int player::get_direction(){return direction;}//0 左， 1右， 2上，3 下
int player::get_size(){return size;}
void player::moveR(){set_direction(1);x+=step;}
void player::moveL(){set_direction(0);x-=step;}
void player::moveU(){set_direction(2);y-=step;}
void player::moveD(){set_direction(3);y+=step;}
void player::set_step(double _step){step=_step;}
double player::get_step(){return step;}
