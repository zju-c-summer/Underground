#include "mainwindow.h"
#include <QtCore>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      game(new GameControl(*scene, this))
{
    setCentralWidget(view);
    resize(WINDOW_SIZE,WINDOW_SIZE);
    QTimer * timer=new QTimer(this);
    timer->start(1);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    //QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{

}
void MainWindow::timerUpDate(){

    resize(WINDOW_SIZE+rand()%2,WINDOW_SIZE+rand()%2);
 //   update();
  //  cout<<"!!!"<<endl;
}




/*
void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}*/
//#include "ui_mainwindow.h"
/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}*/
