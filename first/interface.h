#ifndef INTERFACE_H
#define INTERFACE_H

#include<QWidget>
#include<QPushButton>
#include<QProgressBar>
#include<QTimer>
#include<QLabel>
#include <QMovie>
#include <QPainter>
#include <QStyleOption>
#include <QThread>
#include<QMessageBox>
#include"Carousellmagewindow.h"

class interface:public QWidget
{
    Q_OBJECT
public:
    explicit interface(QWidget *parent = nullptr);

    QLabel* msgLabel;
    QPushButton* startbutton;
    QPushButton* exitbutton;
    QProgressBar* probar;
    QTimer* timer;
    QLabel* label;
    QLabel* Title;
    QMovie* movie;

    QThread* thread;
    CarouselImageWindow* carouse;

protected:
    void paintEvent(QPaintEvent* event);

private:
    void initWidgets();

signals:

public slots:
    void startButton();
    void loading();
    void exitButton();
};

#endif // INTERFACE_H
