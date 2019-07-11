#include "gamecontrol.h"
#include <iostream>
using namespace std;

GameControl::GameControl(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene)
{
    timer.start( 1000/33 );
	maze = nullptr;
    //scene.addItem(maze);
    scene.installEventFilter(this);

   // resume();
}

void GameControl::setModel(mazeModel *maze) {
	this->maze = maze;
	scene.addItem(maze);
}
/*


void GameControl::resume()
{
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
}
void GameControl::timerEvent(QTimerEvent *event){

}*/
void GameControl::handleKeyPressed(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Left :
        maze->moveMan(0);
        break;
    case Qt::Key_Right :
        maze->moveMan(1);
        break;
    case Qt::Key_Up :
        maze->moveMan(2);
        break;
    case Qt::Key_Down :
        maze->moveMan(3);
        break;
    }
   std::cout<<event->key()<<std::endl;
   if(judge()==1){//出口
       //maze->generateMaze();
       playerGetExit();
   }
   else if(judge()==2){
       std::cout<<"no you are dead"<<std::endl;
   }
}
bool GameControl::eventFilter(QObject *object, QEvent *event){
    if(event->type()==QEvent::KeyPress){
        handleKeyPressed((QKeyEvent*)event);
        return true;
    }
    else{
        return QObject::eventFilter(object,event);
    }
}

GameControl::~GameControl()
{

}
int GameControl::judge(){
    if((maze->get_maze())[maze->get_man().get_y()/BLOCK_SIZE][maze->get_man().get_x()/BLOCK_SIZE].get_type()==2){
        return 1;
    }

    double man_x,man_y,monster_x,monster_y;
    double man_x_r,man_y_d,monster_x_r,monster_y_d;
    man_x=maze->get_man().get_x();
    man_y=maze->get_man().get_y();
    monster_x=maze->get_monster().get_x();
    monster_y=maze->get_monster().get_y();
    man_x_r=man_x+maze->get_man().get_size();
    monster_x_r=man_x+maze->get_monster().get_size();
    man_y_d=man_y+maze->get_man().get_size();
    monster_y_d=monster_y+maze->get_monster().get_size();
   // int size=maze->get_man().get_size();

  //  else if
    if(man_x>=monster_x&&man_x<=monster_x_r&&man_y>=monster_y&&man_y<=monster_y_d||monster_x<=man_x_r&&monster_x>=man_x&&monster_y_d>=man_y&&monster_y_d<=man_y_d||
            monster_x<=man_x_r&&monster_x>=man_x&&monster_y>=man_y&&monster_y<=man_y_d||monster_x_r<=man_x_r&&monster_x_r>=man_x&&monster_y>=man_y&&monster_y<=man_y_d){
        std::cout<<"hit the monster"<<endl;
        return 2;//玩家与怪物碰撞
    }
 /*   if((man_x<=monster_x+size&&man_x>=monster_x&&man_y<=monster_y+size&&man_y>=monster_y)||(monster_x<=man_x+size&&monster_x>=man_x&&monster_y<=man_y+size&&monster_y>=man_y)){
        std::cout<<"hit the monster"<<endl;
        return 2;//玩家与怪物碰撞
    }*/
//else todo
    return 0;
}




void GameControl::playerGetExit(){
    maze->generateMaze();
}
