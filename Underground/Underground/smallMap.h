#pragma once

#include<QObject>
#include<QWidget>
#include<QTimer>
#include<QApplication>
#include<QPainter>
#include<cmath>
#include<iostream>
#include"maze.h"

class smallMap :public QWidget {
    Q_OBJECT
private:
    int x, y;
    int des_x, des_y;
	mazeModel* maze;

protected:
    void paintEvent(QPaintEvent *event);
	
public:
    smallMap(QWidget *parent = nullptr, mazeModel* maze = nullptr);
    ~smallMap();
	void setModel(mazeModel *maze);
};

