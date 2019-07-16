#ifndef VIEWER_H
#define VIEWER_H
#include <QTimer>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "game_control.h"

class viewer: public QObject
{
        Q_OBJECT
public:
    viewer(QGraphicsScene * scene,QObject *parent = nullptr);
    ~viewer();
    game_control & get_control(){return control;}
    void update();

private:
    QTimer timer;
    QGraphicsScene * scene;
    game_control control;
protected:
    bool eventFilter(QObject * object,QEvent * event);
private:
    void handleKeyPressed(QKeyEvent *event);
};

#endif // VIEWER_H
