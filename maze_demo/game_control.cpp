#include "game_control.h"
#include <iostream>
#include <QKeyEvent>
using namespace std;

void game_control::playerGetExit(){
    maze->generateMaze();
}
void game_control::keyPress(int i){
    maze->moveMan(i);
    maze->moveMonster(rand()%4);
    if(judge()==1){//出口
        //maze->generateMaze();
        playerGetExit();
    }
    else if(judge()==2){
        std::cout<<"no you are dead"<<std::endl;
    }

}
game_control::game_control() :
    maze(new maze_model())
{
   // resume();

}
game_control::~game_control(){cout<<"~game control"<<endl;}

QRectF game_control::boundingRect() const{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}
void game_control::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);

  //  setPos(-WINDOW_SIZE+100,-WINDOW_SIZE+100);
    int i=0,j;
  /* for(i=0;i<row_size;i++){//-600
        for(j=0;j<maze[i].size();j++){
            painter->setBrush(maze[i][j].get_color());
            painter->drawRect(j*maze[i][j].get_block_size()-man.get_x(),i*maze[i][j].get_block_size()-man.get_y(),maze[i][j].get_block_size(),maze[i][j].get_block_size());
     //       cout<<i<<" "<<j<<" "<<maze[i][j].get_block_size()<<endl;
        }
    }*/
   // maze->get_block(i,j).get_block_size();
    int central_x=(int)maze->get_man().get_x()/BLOCK_SIZE;
    int central_y=(int)maze->get_man().get_y()/BLOCK_SIZE;
    QColor black(0,0,0);
    QColor white(255,255,255);
    QColor lime(0,255,0);
    QPixmap pix;
    painter->setBrush(Qt::black);
    painter->drawRect(-WINDOW_SIZE/2,-WINDOW_SIZE/2,WINDOW_SIZE*1.2,WINDOW_SIZE*1.2);
   // painter->setBrush(black);
   // painter->drawRect(-(PAINT_BLOCK_NUMBER+2)*BLOCK_SIZE,-(PAINT_BLOCK_NUMBER+2)*BLOCK_SIZE,BLOCK_SIZE*(PAINT_BLOCK_NUMBER+2)*2,BLOCK_SIZE*(PAINT_BLOCK_NUMBER+2)*2);

    for(int i=central_y-PAINT_BLOCK_NUMBER-1;i<central_y+PAINT_BLOCK_NUMBER+1;i++){
        for(int j=central_x-PAINT_BLOCK_NUMBER-1;j<central_x+PAINT_BLOCK_NUMBER+1;j++){
            if(i>=0&&i<maze->get_col_size()&&j>=0&&j<maze->get_row_size()){
               /* if(maze->get_block(i,j).get_type()==0)
                painter->setBrush(black);
                else if()*/
                //cout<<"colooo"<<endl;
                switch (maze->get_block(i,j).get_type()) {
                case 0:pix.load(":/new/image/wall_1.png");break;
                case 1:pix.load(":/new/image/wall_dark.png");break;
                case 2: pix.load(":/new/image/exit_2.png");break;
                case 3: pix.load(":/new/image/enter_2.png");break;
                }
                painter->drawPixmap(j*maze->get_block(i,j).get_block_size()-maze->get_man().get_x(),i*maze->get_block(i,j).get_block_size()-maze->get_man().get_y(),maze->get_block(i,j).get_block_size(),maze->get_block(i,j).get_block_size(),pix);
                //painter->drawRect(j*maze->get_block(i,j).get_block_size()-maze->get_man().get_x(),i*maze->get_block(i,j).get_block_size()-maze->get_man().get_y(),maze->get_block(i,j).get_block_size(),maze->get_block(i,j).get_block_size());
                //painter->drawPixmap(j*maze->get_block(i,j).get_block_size()-maze->get_man().get_x(),i*maze->get_block(i,j).get_block_size()-maze->get_man().get_y(),maze->get_block(i,j).get_block_size(),maze->get_block(i,j).get_block_size(),pix);
            }
        }
    }

 //   painter->drawRect(man.get_x(),man.get_y(),man.get_size(),man.get_size());
    if((int)maze->get_monster().get_x()/BLOCK_SIZE>=(central_x-PAINT_BLOCK_NUMBER)&&(int)maze->get_monster().get_y()/BLOCK_SIZE>=(central_y-PAINT_BLOCK_NUMBER)&&
           (int) maze->get_monster().get_x()/BLOCK_SIZE<central_x+PAINT_BLOCK_NUMBER&&(int)maze->get_monster().get_y()/BLOCK_SIZE<central_y+PAINT_BLOCK_NUMBER){
        switch (maze->get_monster().get_direction()) {
        case 0:pix.load(":/new/image/monster_l.png");break;
        case 1:pix.load(":/new/image/monster_r.png");break;
        case 2:pix.load(":/new/image/monster_l.png");break;
        case 3:pix.load(":/new/image/monster_r.png");break;

        }
        painter->drawPixmap(maze->get_monster().get_x()-maze->get_man().get_x(),maze->get_monster().get_y()-maze->get_man().get_y(),maze->get_monster().get_size(),maze->get_monster().get_size(),pix);
     //   QColor monster_color(0,100,0);
       // painter->setBrush(monster_color);//画怪物
       // painter->drawRect(maze->get_monster().get_x()-maze->get_man().get_x(),maze->get_monster().get_y()-maze->get_man().get_y(),maze->get_monster().get_size(),maze->get_monster().get_size());
    }
    //QColor man_color(0,0,255);
   // painter->setBrush(man_color);//画玩家
    switch(maze->get_man().get_direction()){
    case 0:pix.load(":/new/image/man_left_1.png");break;
    case 1:pix.load(":/new/image/man_right_1.png");break;
    case 2:pix.load(":/new/image/man_up_1.png");break;
    case 3:pix.load(":/new/image/man_down_1.png");break;
    }
    painter->drawPixmap(0,0,maze->get_man().get_size(),maze->get_man().get_size(),pix);
   // painter->drawRect(0,0,maze->get_man().get_size(),maze->get_man().get_size());
 //   painter->drawRect(monster.get_x(),monster.get_y(),monster.get_size(),monster.get_size());
    //圆环遮盖
    QColor white_op(255,255,255,0);
    QColor black_op(0,0,0,255);
    QRadialGradient radialGradient(0,0,(PAINT_BLOCK_NUMBER+2)*BLOCK_SIZE*1.6,0,0);
    radialGradient.setColorAt(0.4,white_op);
    radialGradient.setColorAt(0.44,black_op);
    radialGradient.setSpread(QGradient::PadSpread);
    int radius = (PAINT_BLOCK_NUMBER+1)*BLOCK_SIZE*1.6;
        painter->save();
        painter->setPen(white_op);
        painter->setBrush(QBrush(radialGradient));
        //painter->setOpacity(0.5);
        QPainterPath bigCircle;
        bigCircle.addEllipse(-radius, -radius, radius * 2, radius * 2);

        radius = PAINT_BLOCK_NUMBER*BLOCK_SIZE*0.6;
        QPainterPath smallCircle;
        smallCircle.addEllipse(-radius, -radius, radius * 2, radius * 2);

        QPainterPath path = bigCircle - smallCircle;
        painter->drawPath(path);

        painter->restore();
}
int game_control::judge(){
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
    int size=maze->get_man().get_size();

  //  else if
    if(man_x>=monster_x&&man_x<=monster_x_r&&man_y>=monster_y&&man_y<=monster_y_d||monster_x<=man_x_r&&monster_x>=man_x&&monster_y_d>=man_y&&monster_y_d<=man_y_d||
            monster_x<=man_x_r&&monster_x>=man_x&&monster_y>=man_y&&monster_y<=man_y_d||monster_x_r<=man_x_r&&monster_x_r>=man_x&&monster_y>=man_y&&monster_y<=man_y_d){
        std::cout<<"hit the monster"<<endl;
        return 2;//玩家与怪物碰撞
    }
//else todo
    return 0;
}




/*

void GameControl::resume()
{
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
}
void GameControl::timerEvent(QTimerEvent *event){

}*//*
void game_control::handleKeyPressed(QKeyEvent *event){
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
bool game_control::eventFilter(QObject *object, QEvent *event){
    if(event->type()==QEvent::KeyPress){
        handleKeyPressed((QKeyEvent*)event);
        return true;
    }
    else{
        return QObject::eventFilter(object,event);
    }
}

game_control::~game_control()
{

}
int game_control::judge(){
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
    if((man_x<=monster_x+size&&man_x>=monster_x&&man_y<=monster_y+size&&man_y>=monster_y)||(monster_x<=man_x+size&&monster_x>=man_x&&monster_y<=man_y+size&&monster_y>=man_y)){
        std::cout<<"hit the monster"<<endl;
        return 2;//玩家与怪物碰撞
    }
//else todo
    return 0;
}*/
