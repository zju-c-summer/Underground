#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "ui_mainwindow.h"
#include "smallMap.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QTimer>
#include "gamecontrol.h"

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
	smallMap *smap;
    GameControl *game;
	mazeModel *maze;
};



#endif // MAINWINDOW_H
