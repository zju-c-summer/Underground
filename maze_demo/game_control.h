#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
//#include "maze_model.h"
#include "smallMap.h"
class game_control : public QGraphicsItem
{
public:
    game_control();
    ~game_control();
    QRectF boundingRect()const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void keyPress(int i);
    maze_model * get_maze(){return maze;}
protected:
    void playerGetTreasure();
    void playerGetExit();
    void playerMeetMonser();
    int judge();
//    bool eventFilter(QObject * object,QEvent * event);
private:
 //   void handleKeyPressed(QKeyEvent *event);
    //0无事发生，1进入出口格，2进入宝箱格，3与怪物相遇
  /*  void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);*/

    maze_model * maze;
   // smallMap * map;
};

#endif // GAME_CONTROL_H
