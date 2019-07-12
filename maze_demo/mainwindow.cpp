#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene, this)),
    viewer_m(new viewer(scene, this)),
    map(viewer_m->get_control().get_maze(),this)
{
   // setStyleSheet("background-color:black;");
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
  //  setFixedSize(this->width(),this->height());

   // initcharacter();
    initwidget();
    setCentralWidget(view);
    resize(WINDOW_SIZE,WINDOW_SIZE);
    QTimer * timer=new QTimer(this);
    timer->start(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));

    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::black);
    this->setPalette(palette);
}

void MainWindow::initwidget()
{
    //初始化界面控件
    surface = new interface(this);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    switch (QMessageBox::information(this,tr("exit tip"),tr("Do you really want to exit?"),tr("Yes"),tr("No"),0,1))
    {
    case 0:
        event->accept();
        break;
    case 1:
    default:
        event->ignore();
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpDate(){

  resize(WINDOW_SIZE+rand()%2,WINDOW_SIZE+rand()%2);
 //   update();
   // repaint();
  //  cout<<"!!!"<<endl;
}
void MainWindow::showEvent(QShowEvent *e)

{
    this->setAttribute(Qt::WA_Mapped);
    QWidget::showEvent(e);
}
