#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene.get(), this)),
    viewer_m(new viewer(scene.get(), this)),
    map(new smallMap(this))
{
   // setStyleSheet("background-color:black;");
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
  //  setFixedSize(this->width(),this->height());
    update_view_notification = std::static_pointer_cast<Notification, MainWindowNotification>(std::shared_ptr<MainWindowNotification>(new MainWindowNotification));
    std::static_pointer_cast<MainWindowNotification, Notification>(update_view_notification)->setView(std::shared_ptr<MainWindow>(this));
   // initcharacter();
    initwidget();
    setCentralWidget(view.get());
    resize(WINDOW_SIZE,WINDOW_SIZE);
    QTimer * timer=new QTimer(this);
    timer->start(750);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));


    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::black);
    this->setPalette(palette);
    std::cout << "ok" << std::endl;
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
    //delete ui;
}

std::shared_ptr<viewer> MainWindow::get_viewer(){
    return viewer_m;
}

std::shared_ptr<smallMap> MainWindow::get_smallMap(){
    return map;
}

std::shared_ptr<Notification> MainWindow::get_view_notification(){
    return update_view_notification;
}

void MainWindow::timerUpDate(){
    viewer_m->get_control().mons_move();
  //resize(WINDOW_SIZE+rand()%2,WINDOW_SIZE+rand()%2);
 //   update();
   // repaint();
  //  cout<<"!!!"<<endl;
}
void MainWindow::showEvent(QShowEvent *e)

{
    this->setAttribute(Qt::WA_Mapped);
    QWidget::showEvent(e);
}
