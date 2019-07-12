#pragma once

#include<QObject>
#include<QWidget>
#include<QTimer>
#include<QApplication>
#include<QPainter>
#include<cmath>
#include<iostream>
#include "maze_model.h"

class smallMap :public QWidget {
    Q_OBJECT
private:
    double x, y;
    int des_x, des_y;
    maze_model * maze;
protected:
    void paintEvent(QPaintEvent *event);
public:
    smallMap(maze_model * maz,QWidget *parent = nullptr);
    ~smallMap();
    void updatePos();

};

