#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include <QObject>
#include <vector>
#include <iostream>
#include "player.h"
#include "block.h"
using namespace std;

class player;
class block;

class maze_model : public QObject{
private:
    unsigned int row_size;
    unsigned int col_size;
    vector<vector<block>>  maze;
    int des_x,des_y;
    player man;
    player monster;
public:
    int get_des_x(){return des_x;}
    int get_des_y(){return des_y;}
    unsigned int get_row_size(){return row_size;}
    unsigned int get_col_size(){return col_size;}
    player & get_man();
    player & get_monster();
    void moveMan(int _direction);
    void moveMonster(int _direction);
    void init();
    block & get_block(int i,int j);
    vector<vector<block>> & get_maze();
    maze_model();
    void set_block(int row,int col,int type,QColor color,int size);
    void generateMaze();
protected:

    void advance(int step);

};

#endif // MAZE_MODEL_H
