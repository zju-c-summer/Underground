#include "viewer.h"

viewer::viewer(QGraphicsScene * scene,QObject *parent): QObject(parent),scene(scene)
{    timer.start( 1000/33 );
     scene->addItem(&control);
    // scene.addItem(&map);
     scene->installEventFilter(this);
}
void viewer::handleKeyPressed(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Left :
        control.keyPress(0);
       // maze->moveMan(0);
        break;
    case Qt::Key_Right :
      //  maze->moveMan(1);
        control.keyPress(1);
        break;
    case Qt::Key_Up :
      //  maze->moveMan(2);
        control.keyPress(2);
        break;
    case Qt::Key_Down :
     //   maze->moveMan(3);
        control.keyPress(3);
        break;
    }
   std::cout<<event->key()<<std::endl;
}
bool viewer::eventFilter(QObject *object, QEvent *event){
    if(event->type()==QEvent::KeyPress){
        handleKeyPressed((QKeyEvent*)event);
        return true;
    }
    else{
        return QObject::eventFilter(object,event);
    }
}
viewer::~viewer(){
    cout<<"~viewer"<<endl;
}
