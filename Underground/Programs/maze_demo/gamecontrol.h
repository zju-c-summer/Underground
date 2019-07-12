#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "maze.h"

//class mazeModel;
class GameControl : public QObject
{
    Q_OBJECT
public:
    GameControl(QGraphicsScene & scene,QObject *parent = 0);
    ~GameControl();

    void playerGetTreasure();
    void playerGetExit();
    void playerMeetMonser();
protected:
    bool eventFilter(QObject * object,QEvent * event);
private:
    void handleKeyPressed(QKeyEvent *event);
    int judge();//0无事发生，1进入出口格，2进入宝箱格，3与怪物相遇
  /*  void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);*/
    QTimer timer;
    QGraphicsScene &scene;

    mazeModel * maze;
};
#endif // GAMECONTROL_H
