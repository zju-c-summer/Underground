#include "maze_model.h"
#include "prim.h"
#include <iostream>
using namespace std;
vector<vector <block>> & maze_model::get_maze(){return maze;}
player & maze_model:: get_man() {return man;}
player & maze_model::get_monster(){return monster;}
block & maze_model::get_block(int i,int j){return maze[i][j];}
void maze_model::moveMan(int _direction){
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
}
void maze_model::init(){
    for(unsigned int i=0;i<row_size;i++){
        for(unsigned int j=0;j<col_size;j++){
        //   cout<<i<<" "<<j<<endl;
            QColor temp(255,255,255);
            set_block(i,j,0,temp,BLOCK_SIZE);
        }
    }
}
maze_model::maze_model():row_size(MAZE_SIZE),col_size(MAZE_SIZE),man(){
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
void maze_model::set_block(int row,int col,int type,QColor color,int size){
    maze[row][col].set_type(type);
  //  maze[row][col].set_color(color);
    maze[row][col].set_block_size(size);
}
void maze_model::generateMaze(){

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
            }

            else {
               maze[i][j].set_type(1);
            }
        }
    }
    int ranRow=rand()%(row_size-2)+1;
    int ranCol=rand()%(col_size-2)+1;
    while(maze[ranRow][ranCol].get_type()==0){
        ranRow=rand()%(row_size-2)+1;
        ranCol=rand()%(col_size-2)+1;
    }
    maze[ranRow][ranCol].set_type(2);
    des_x=maze[ranRow][ranCol].get_x();
    des_y=maze[ranRow][ranCol].get_y();
 //   maze[ranRow][ranCol].set_color(lime);
    do{
        ranRow=rand()%(row_size-2)+1;
        ranCol=rand()%(col_size-2)+1;
    }while(maze[ranRow][ranCol].get_type()==0||maze[ranRow][ranCol].get_type()==2);
    maze[ranRow][ranCol].set_type(3);
 //   maze[ranRow][ranCol].set_color(orange);
    man.set_x(maze[ranRow][ranCol].get_block_size()*ranCol+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    man.set_y(maze[ranRow][ranCol].get_block_size()*ranRow+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    do{
        ranRow=rand()%(row_size-2)+1;
        ranCol=rand()%(col_size-2)+1;
    }while(maze[ranRow][ranCol].get_type()==0||maze[ranRow][ranCol].get_type()==2||maze[ranRow][ranCol].get_type()==3);
    monster.set_x(maze[ranRow][ranCol].get_block_size()*ranCol+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    monster.set_y(maze[ranRow][ranCol].get_block_size()*ranRow+maze[ranRow][ranCol].get_block_size()/2-man.get_size()/2);
    delete []s;
}
