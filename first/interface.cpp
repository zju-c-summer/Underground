#include "interface.h"
#include"Carousellmagewindow.h"
#include<QPalette>
#include<QPixmap>
#include<QFont>
#include<QThread>
#include<QApplication>
#include<QLabel>
#include<QRect>
#include<QMessageBox>
#include<QDebug>

interface::interface(QWidget *parent) :
    QWidget(parent)
{

    setGeometry(0,0,960,720);

    initWidgets();


    carouse = new CarouselImageWindow(this);
    carouse->addImage(":/new/image/image1.jpg");
    carouse->addImage(":/new/image/image2.jpg");
    carouse->addImage(":/new/image/image3.jpg");
    carouse->setGeometry(0,0,960,720);
    carouse->hide();

    label = new QLabel(this);
    label->setGeometry(330,150,400,400);
    label->setContentsMargins(0,0,0,0);
    movie=new QMovie(":/new/image/loading.gif");
    label->setMovie(movie);
    label->hide();

    /*msgLabel = new QLabel(this);
    msgLabel->setGeometry(320,250,100,75);
    msgLabel->setFont(QFont("宋体",13));
    msgLabel->hide();*/
}

void interface::paintEvent(QPaintEvent *event)
{
    QPainter* painter = new QPainter(this);
    QImage pixmap(":/new/image/background.png");
    painter->drawImage(geometry(),pixmap);
}

void interface::initWidgets()
{
    probar = new QProgressBar(this);
    probar->setGeometry(80,650,800,20);
    QString probar_ss = "QProgressBar "
                        "{border: 2px solid grey;"
                        " border-radius: 5px;"
                        " background-color: #FFFFFF;"
                        "}"
                        "QProgressBar::chunk "
                        "{background-color: #05B8CC;"
                        " width:20px;"
                        "}"
                        "QProgressBar "
                        "{border: 2px solid grey;"
                        " border-radius: 5px;"
                        " text-align: center;"
                        "}";
    probar->setStyleSheet(probar_ss);
    probar->setTextVisible(true);
    probar->hide();

    Title = new QLabel(this);
    QImage *img=new QImage;
    img ->load(":/new/image/title.png");
    Title->setPixmap(QPixmap::fromImage(*img));
    Title->setGeometry(100,0,800,200);



    this->thread = new QThread(this);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(loading()));


    startbutton = new QPushButton(this);
    startbutton->setGeometry(650,400,200,100);
    startbutton->setStyleSheet("QPushButton{border-image: url(:/new/image/playbutton.png)}"
                          "QPushButton:hover{border-image:url(:/new/image/playbutton_hover.png)}"
                          "QPushButton:pressed{border-image:url(:/new/image/playbutton_pressed.png)}");
    connect(startbutton,SIGNAL(clicked()),this,SLOT(startButton()));

    exitbutton = new QPushButton(this);
    exitbutton->setGeometry(650,500,200,100);
    exitbutton->setStyleSheet("QPushButton{border-image: url(:/new/image/exitbutton.png)}"
                          "QPushButton:hover{border-image:url(:/new/image/exitbutton_hover.png)}"
                          "QPushButton:pressed{border-image:url(:/new/image/exitbutton_pressed.png)}");
    connect(exitbutton,SIGNAL(clicked()),this,SLOT(exitButton()));

}

void interface::startButton()
{
    startbutton->hide();
    exitbutton->hide();
    Title->hide();
//    label->show();
//    movie->start();

    carouse->startPlay();
    carouse->raise();
    carouse->show();


    timer->start(100);
    probar->show();

}

void interface::loading()
{
    probar->setValue(probar->value()+2);
    if(probar->value()>=99)
        delete this;
}

void interface::exitButton()
{
    if(!(QMessageBox::information(this,tr("exit tip"),tr("Do you really want to exit?"),tr("Yes"),tr("No"))))
    {
        QApplication* app;
        app->exit(0);
    }
}
