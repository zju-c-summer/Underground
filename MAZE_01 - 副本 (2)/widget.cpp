//#include "widget.h"
//#include "ui_widget.h"
//#include <QGraphicsView>
/*
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this)),
    viewer_m(*scene,parent)
{
    ui->setupUi(this);

    resize(WINDOW_SIZE,WINDOW_SIZE);
    QTimer * timer=new QTimer(this);
    timer->start(1);
  //  connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
}

Widget::~Widget()
{
    delete ui;
}*/
#include "widget.h"
#include <QtCore>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      viewer_m(new viewer(scene, this)),
      map(viewer_m->get_control().get_maze(),this)
{
    setCentralWidget(view);
    resize(WINDOW_SIZE,WINDOW_SIZE);
    QTimer * timer=new QTimer(this);
    timer->start(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{
    cout<<"main window"<<endl;
}
void MainWindow::timerUpDate(){

  resize(WINDOW_SIZE+rand()%2,WINDOW_SIZE+rand()%2);
   // update();
   // repaint();
  //  cout<<"!!!"<<endl;
}
