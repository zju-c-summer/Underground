#ifndef WIDGET_H
#define WIDGET_H
/*
#include <QWidget>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    viewer viewer_m;
};*/

//#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
//#include "gamecontrol.h"
#include "viewer.h"
namespace Ui {
class MainWindow;
}

//#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
   // void adjustViewSize();
    void timerUpDate();

private:

    QGraphicsScene *scene;
    QGraphicsView *view;

    viewer *viewer_m;
    smallMap map;
};

#endif // WIDGET_H
