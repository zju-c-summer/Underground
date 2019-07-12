#include "commentvalue.h"
#include "maze.h"
#include <iostream>
using namespace std;
player & mazeModel:: get_man() {return man;}
player & mazeModel::get_monster(){return monster;}
void mazeModel::moveMan(int _direction){
 //   int i,j;
  //  i=BLOCK_SIZE/man.get_x();
    //j=BLOCK_SIZE/man.get_y();
    man.set_direction(_direction);
    cout<<"in here"<<endl;
   if(man.get_direction()==0){//试着往左走
       // i++;
        if(maze[(int)man.get_y()/BLOCK_SIZE][(int)man.get_x()/BLOCK_SIZE-1].get_type()==0&&man.get_x()-((int)man.get_x()/BLOCK_SIZE)*BLOCK_SIZE<=man.get_step()){

            cout<<"move r"<<endl;
        }
        else{
            man.moveL();
            cout<<"move l r"<<endl;
        }
    }
    else if(man.get_direction()==1){
       // i++;
        //j+=2;
        if(maze[(int)man.get_y()/BLOCK_SIZE][(int)man.get_x()/BLOCK_SIZE+1].get_type()==0&&((int)man.get_x()/BLOCK_SIZE+1)*BLOCK_SIZE-man.get_x()-man.get_size()<=man.get_step()){
          //  man.moveL();
            cout<<"move l"<<endl;
        }
        else{
            man.moveR();
            cout<<"move r l"<<endl;
        }
    }
    else if(man.get_direction()==2){
      //  j++;
        if(maze[(int)man.get_y()/BLOCK_SIZE-1][(int)man.get_x()/BLOCK_SIZE].get_type()==0&&man.get_y()-((int)man.get_y()/BLOCK_SIZE)*BLOCK_SIZE<=man.get_step()){
          //  man.moveD();
            cout<<"move d"<<endl;
        }
        else{
            man.moveU();
            cout<<"move d u"<<endl;
        }
    }
    else{
        if(maze[(int)man.get_y()/BLOCK_SIZE+1][(int)man.get_x()/BLOCK_SIZE].get_type()==0&&((int)man.get_y()/BLOCK_SIZE+1)*BLOCK_SIZE-man.get_y()-man.get_size()<=man.get_step()){
          //  man.moveU();
            cout<<"move u"<<endl;
        }
        else{
            man.moveD();
            cout<<"move u d"<<endl;
        }
    }
 /*   if(man.get_direction()==0) man.moveL();
    else if (man.get_direction()==1) man.moveR();
    else if (man.get_direction()==2) man.moveU();
    else if (man.get_direction()==3) man.moveD();*/
    update();
}
void mazeModel::init(){
    for(unsigned int i=0;i<row_size;i++){
        for(unsigned int j=0;j<col_size;j++){
        //   cout<<i<<" "<<j<<endl;
            QColor temp(255,255,255);
            set_block(i,j,0,temp,BLOCK_SIZE);
        }
    }
}
mazeModel::mazeModel():row_size(MAZE_SIZE),col_size(MAZE_SIZE),man(){
    //this->grabKeyboard();
    maze.resize(row_size);
  //  cout<<row_size<<endl;
 //   cout<<maze.size()<<endl;
 //   cout<<col_size<<endl;
    for(unsigned int i=0;i<maze.size();i++){
     //   cout<<i<<endl;
        maze[i].resize(col_size);
        for(int j=0;j<maze[i].size();j++){
            maze[i][j].set_x(j);
            maze[i][j].set_y(i);
        }
    }
    //init();
    generateMaze();
}
void mazeModel::set_block(int row,int col,int type,QColor color,int size){
    maze[row][col].set_type(type);
    maze[row][col].set_color(color);
    maze[row][col].set_block_size(size);
}
QRectF mazeModel::boundingRect() const{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}
void mazeModel::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option,
           QWidget *widget){
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
    int central_x=(int)man.get_x()/BLOCK_SIZE;
    int central_y=(int)man.get_y()/BLOCK_SIZE;
    QColor black(0,0,0);
    painter->setBrush(black);
    painter->drawRect(-(PAINT_BLOCK_NUMBER+2)*BLOCK_SIZE,-(PAINT_BLOCK_NUMBER+2)*BLOCK_SIZE,BLOCK_SIZE*(PAINT_BLOCK_NUMBER+2)*2,BLOCK_SIZE*(PAINT_BLOCK_NUMBER+2)*2);

    for(int i=central_y-PAINT_BLOCK_NUMBER;i<central_y+PAINT_BLOCK_NUMBER;i++){
        for(int j=central_x-PAINT_BLOCK_NUMBER;j<central_x+PAINT_BLOCK_NUMBER;j++){
            if(i>=0&&i<maze.size()&&j>=0&&j<maze.size()){
                painter->setBrush(maze[i][j].get_color());
                painter->drawRect(j*maze[i][j].get_block_size()-man.get_x(),i*maze[i][j].get_block_size()-man.get_y(),maze[i][j].get_block_size(),maze[i][j].get_block_size());
            }
        }
    }
    painter->setBrush(man.get_color());//画玩家
    painter->drawRect(0,0,man.get_size(),man.get_size());
 //   painter->drawRect(man.get_x(),man.get_y(),man.get_size(),man.get_size());
    painter->setBrush(monster.get_color());//画怪物
    painter->drawRect(monster.get_x()-man.get_x(),monster.get_y()-man.get_y(),monster.get_size(),monster.get_size());
 //   painter->drawRect(monster.get_x(),monster.get_y(),monster.get_size(),monster.get_size());

}
void mazeModel::generateMaze(){

    Coordinate * s =new Coordinate[row_size*col_size];
    PrimeMap(s,row_size);
    int i,j;
    QColor black(0,0,0);
    QColor white(255,255,255);
    QColor lime(0,255,0);
    QColor orange(255,140,0);
    init();
    for(i=0;i<row_size;i++){
        for(j=0;j<col_size;j++){
            if(s[i*row_size+j].Judgment==1){
                 maze[i][j].set_type(0);
                 maze[i][j].set_color(black);
            }

            else {
               maze[i][j].set_type(1);
               maze[i][j].set_color(white);
            }
        }
    }
    int ranRow=rand()%(row_size-2)+1;
    int ranCol=rand()%(col_size-2)+1;
    while(!maze[ranRow][ranCol].get_type()){
        ranRow=rand()%(row_size-2)+1;
        ranCol=rand()%(col_size-2)+1;
    }
    maze[ranRow][ranCol].set_type(2);
    maze[ranRow][ranCol].set_color(lime);
    do{
        ranRow=rand()%(row_size-2)+1;
        ranCol=rand()%(col_size-2)+1;
    }while(!maze[ranRow][ranCol].get_type()&&!maze[ranRow][ranCol].get_type()==2);
    maze[ranRow][ranCol].set_type(3);
    maze[ranRow][ranCol].set_color(orange);
    man.set_x(maze[ranRow][ranCol].get_block_size()*ranCol+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    man.set_y(maze[ranRow][ranCol].get_block_size()*ranRow+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    do{
        ranRow=rand()%(row_size-2)+1;
        ranCol=rand()%(col_size-2)+1;
    }while(!maze[ranRow][ranCol].get_type()&&!maze[ranRow][ranCol].get_type()==2&&!maze[ranRow][ranCol].get_type()==3);
    monster.set_x(maze[ranRow][ranCol].get_block_size()*ranCol+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    monster.set_y(maze[ranRow][ranCol].get_block_size()*ranRow+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    delete []s;
}
void mazeModel::advance(int step){
    QPainter painter;
    painter.eraseRect(0,0,1200,1200);
    cout<<"update"<<endl;
    update();//QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget
}
