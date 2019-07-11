#include "block.h"
#include "common_value.h"
block::block():type(0),block_size(BLOCK_SIZE),x(0),y(0){}
void block::set_type(int typ){type=typ;}
// void set_color(QColor colo){color=colo;}
void block::set_block_size(int size){block_size=size;}
int block::get_block_size(){return block_size;}
int block::get_type(){return type;}
//  QColor get_color(){return color;}
void block::set_x(int _x){x=_x;}
void block::set_y(int _y){y=_y;}
int block::get_x(){return x;}
int block::get_y(){return y;}
