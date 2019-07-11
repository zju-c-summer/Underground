#include "mainwin.h"

mainWin::mainWin(QWidget *parent):QWidget(parent){
    setGeometry(100, 100, 1500, 1500);
    setHidden(true);
    /*小地图*/
    sMap = new smallMap(this);
    //sMap->hide();
    sMap->move(10, 10);
    sMap->setVisible(false);

    /*大地图*/
    mMap = nullptr;

    keyState = 0;
    moveTimerId = 0;
    flashTimerId = 0;
    /**/
}

mainWin::~mainWin(){
    delete sMap;
    delete mMap;
}

void mainWin::TimerEvent(QTimerEvent *event){
    if(isVisible() == false) return;
    int tId = event->timerId();
    if(tId == moveTimerId){

    }
    else if(tId ==  flashTimerId){
        update();
    }
}

void mainWin::KeyPressedEvent(QKeyEvent *event) {
    int key = event->key();
    switch(key){
    case Qt::Key_Up: if(event->isAutoRepeat() || keyState) break;

    case Qt::Key_Down: if(event->isAutoRepeat() || keyState) break;

    case Qt::Key_Left: if(event->isAutoRepeat() || keyState) break;

    case Qt::Key_Right: if(event->isAutoRepeat() || keyState) break;
        keyState = key;
        moveTimerId = startTimer(25);
        break;
    default: break;
    }

}

void mainWin::KeyReleasedEvent(QKeyEvent *event){
    int key = event->key();
    if(key == keyState){
        keyState = 0;
        killTimer(moveTimerId);
    }
}

void mainWin::start(){
	sMap->setVisible(true);
}
