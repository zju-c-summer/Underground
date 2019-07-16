#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include <QObject>
#include <vector>
#include <iostream>
#include "..\common\player.h"
#include "..\common\block.h"
#include "..\common\base.h"
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
    std::shared_ptr<Notification> update_display_data_notification;
public:
    int get_des_x(){return des_x;}//获取出口x坐标
    int get_des_y(){return des_y;}//获取出口y坐标
    unsigned int get_row_size(){return row_size;}//获取迷宫宽度
    unsigned int get_col_size(){return col_size;}//获取迷宫长度
    player & get_man();//获得玩家
    player & get_monster();//获得怪物
    void moveMan(int _direction);//移动玩家
    void moveMonster(int _direction);//移动怪物
    void init();//初始化迷宫
    block & get_block(int i,int j);//获得迷宫中某一单元格
    vector<vector<block>> & get_maze();//获得整个迷宫的二维数组
    maze_model();//构造函数
    void set_block(int row,int col,int type,QColor color,int size);//设置某一单元格的属性
    void generateMaze();//随机生成迷宫
    void set_update_display_data_notification(std::shared_ptr<Notification> notification);
protected:

    void advance(int step);

};

#endif // MAZE_MODEL_H
