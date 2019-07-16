#pragma once

#include<QObject>
#include<QWidget>
#include<QTimer>
#include<QApplication>
#include<QPainter>
#include<cmath>
#include<iostream>
//#include "maze_model.h"
#include "../../utility/common/player.h"
#include "../../utility/common/base.h"
#include "smallmap_notification.h"




class smallMap :public QWidget {
    Q_OBJECT
private:
    std::shared_ptr<player> man;
    std::shared_ptr<int> des_x;
    std::shared_ptr<int> des_y;
    std::shared_ptr<Notification> update_view_notification;
    //maze_model * maze;
protected:
    void paintEvent(QPaintEvent *event);
public:
    smallMap(QWidget *parent = nullptr);
    ~smallMap();
    //void updatePos();
    void bindPlayer(std::shared_ptr<player> man);
    void bindDesc(std::shared_ptr<int> x, std::shared_ptr<int> y);
    std::shared_ptr<Notification> getNotification();
};



