#pragma once

#include<QObject>
#include<QWidget>
#include<QApplication>
#include<QPainter>
#include<QMainWindow>
#include<cmath>
#include<iostream>
#include<QTimer>
#include<QKeyEvent>
#include<QtCore/qnamespace.h>
#include"smallMap.h"
using namespace std;

class mainWin : public QWidget
{
    Q_OBJECT
public:
    mainWin(QWidget *parent);
	~mainWin();
	void start();
protected:
    void KeyPressedEvent(QKeyEvent *event);
    void TimerEvent(QTimerEvent *event);
	void KeyReleasedEvent(QKeyEvent *event);
private:
    QWidget* sMap;
    QWidget* mMap;
	int moveTimerId;
	int flashTimerId;
    int keyState;
};


