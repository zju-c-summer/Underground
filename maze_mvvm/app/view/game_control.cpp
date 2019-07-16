#include "game_control.h"
#include <iostream>
#include <QKeyEvent>
#include <QObject>
#include <QApplication>
#include <QMessageBox>
#include<QLabel>
#include<QRect>
using namespace std;

void game_control::playerGetExit(){
    generate_command->exec();
}
void game_control::keyPress(int i){
    //mons_flush_command->exec();
    switch(i){
    case 0: move_command->set_parameters(std::static_pointer_cast<Parameters, DirectionParameters>(shared_ptr<DirectionParameters>(new DirectionParameters("Left"))));
        move_command->exec();
        break;
    case 1: move_command->set_parameters(std::static_pointer_cast<Parameters, DirectionParameters>(shared_ptr<DirectionParameters>(new DirectionParameters("Right"))));
        move_command->exec();
        break;
    case 2: move_command->set_parameters(std::static_pointer_cast<Parameters, DirectionParameters>(shared_ptr<DirectionParameters>(new DirectionParameters("Up"))));
        move_command->exec();
        break;
    case 3: move_command->set_parameters(std::static_pointer_cast<Parameters, DirectionParameters>(shared_ptr<DirectionParameters>(new DirectionParameters("Down"))));
        move_command->exec();
        break;
    default:
        break;

    }
    if(judge()==1){//出口
        playerGetExit();
    }
    else if(judge()==2){
        //std::cout<<"no you are dead"<<std::endl;
        if(!(QMessageBox::information(nullptr,QString("exit tip"),QString("You are dead!"),QString("No, I quit"),QString("Try again"))))
        {
            //QApplication* app;
            QApplication::exit(0);
        }
        else{
            generate_command->exec();
        }
    }

}
game_control::game_control()
{
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


    int i=0,j;

    int central_x=(int)man->get_x()/BLOCK_SIZE;
    int central_y=(int)man->get_y()/BLOCK_SIZE;
    QColor black(0,0,0);
    QColor white(255,255,255);
    QColor lime(0,255,0);
    QPixmap pix;
    painter->setBrush(Qt::black);
    painter->drawRect(-WINDOW_SIZE/2,-WINDOW_SIZE/2,WINDOW_SIZE*1.2,WINDOW_SIZE*1.2);

    for(int i=central_y-PAINT_BLOCK_NUMBER-1;i<central_y+PAINT_BLOCK_NUMBER+1;i++){
        for(int j=central_x-PAINT_BLOCK_NUMBER-1;j<central_x+PAINT_BLOCK_NUMBER+1;j++){
            if(i>=0&&i<(*col_size)&&j>=0&&j<(*row_size)){
                switch ((*maze)[i][j].get_type()) {
                case 0:pix.load(":/new/image/wall_1.png");break;
                case 1:pix.load(":/new/image/wall_dark.png");break;
                case 2: pix.load(":/new/image/exit_2.png");break;
                case 3: pix.load(":/new/image/enter_2.png");break;
                }
                painter->drawPixmap(j*(*maze)[i][j].get_block_size()-man->get_x(),i*(*maze)[i][j].get_block_size()-man->get_y(),(*maze)[i][j].get_block_size(),(*maze)[i][j].get_block_size(),pix);
            }
        }
    }

    if((int)mons->get_x()/BLOCK_SIZE>=(central_x-PAINT_BLOCK_NUMBER)&&(int)mons->get_y()/BLOCK_SIZE>=(central_y-PAINT_BLOCK_NUMBER)&&
           (int) mons->get_x()/BLOCK_SIZE<central_x+PAINT_BLOCK_NUMBER&&(int)mons->get_y()/BLOCK_SIZE<central_y+PAINT_BLOCK_NUMBER){
        switch (mons->get_direction()) {
        case 0:pix.load(":/new/image/monster_l.png");break;
        case 1:pix.load(":/new/image/monster_r.png");break;
        case 2:pix.load(":/new/image/monster_l.png");break;
        case 3:pix.load(":/new/image/monster_r.png");break;

        }
        painter->drawPixmap(mons->get_x()-man->get_x(),mons->get_y()-man->get_y(),mons->get_size(),mons->get_size(),pix);
    }
    switch(man->get_direction()){
    case 0:pix.load(":/new/image/man_left_1.png");break;
    case 1:pix.load(":/new/image/man_right_1.png");break;
    case 2:pix.load(":/new/image/man_up_1.png");break;
    case 3:pix.load(":/new/image/man_down_1.png");break;
    }
    painter->drawPixmap(0,0,man->get_size(),man->get_size(),pix);
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
    if((*maze)[man->get_y()/BLOCK_SIZE][man->get_x()/BLOCK_SIZE].get_type()==2){
        return 1;
    }

    double man_x,man_y,monster_x,monster_y;
    double man_x_r,man_y_d,monster_x_r,monster_y_d;
    man_x=man->get_x();
    man_y=man->get_y();
    monster_x=mons->get_x();
    monster_y=mons->get_y();
    man_x_r=man_x+man->get_size();
    monster_x_r=monster_x+mons->get_size();
    man_y_d=man_y+man->get_size();
    monster_y_d=monster_y+man->get_size();
    int size=man->get_size();

  //  else if
    if(man_x>=monster_x&&man_x<=monster_x_r&&man_y>=monster_y&&man_y<=monster_y_d||monster_x<=man_x_r&&monster_x>=man_x&&monster_y_d>=man_y&&monster_y_d<=man_y_d||
            monster_x<=man_x_r&&monster_x>=man_x&&monster_y>=man_y&&monster_y<=man_y_d||monster_x_r<=man_x_r&&monster_x_r>=man_x&&monster_y>=man_y&&monster_y<=man_y_d){
        //std::cout<<"hit the monster"<<endl;
        return 2;//玩家与怪物碰撞
    }
//else todo
    return 0;
}

void game_control::bindMaze(std::shared_ptr<std::vector<std::vector<block> > > Maze){
    maze = Maze;
}
void game_control::bindPlayer(std::shared_ptr<player> Man){
    man = Man;
}
void game_control::bindMonster(std::shared_ptr<player> Mon){
    mons = Mon;
}
void game_control::bindDesc(std::shared_ptr<int> X,
              std::shared_ptr<int> Y){
    des_x = X;
    des_y = Y;
}
void game_control::bindSize(std::shared_ptr<std::size_t> row_size,
                            std::shared_ptr<std::size_t> col_size){
    this->row_size = row_size;
    this->col_size = col_size;
}

void game_control::set_move_command(std::shared_ptr<Command> command){
    move_command = command;
}

void game_control::set_generate_command(std::shared_ptr<Command> command){
    generate_command = command;
}

void game_control::set_mons_flush_command(std::shared_ptr<Command> command){
    mons_flush_command = command;
}


void game_control::mons_move(){
    if(mons_flush_command.get() != nullptr){
        mons_flush_command->exec();
    }
}

