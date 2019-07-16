#pragma once

#include <QMainWindow>
#include"interface.h"
#include"Carousellmagewindow.h"
#include <QStack>
#include <QVector>
#include <QQueue>
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QSequentialAnimationGroup>
#include "../view/viewer.h"
#include "../view/smallMap.h"
#include "../../utility/common/base.h"
#include "mainwindow_notification.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    interface* surface;

protected:
    void closeEvent(QCloseEvent *event);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initwidget();
    void initcharacter();
    void showEvent(QShowEvent *event);

    std::shared_ptr<viewer> get_viewer();
    std::shared_ptr<smallMap> get_smallMap();

    std::shared_ptr<Notification> get_view_notification();

private slots:
    void timerUpDate();

private:
    Ui::MainWindow* ui;
    std::shared_ptr<QGraphicsScene> scene;
    std::shared_ptr<QGraphicsView> view;

    std::shared_ptr<viewer> viewer_m;
    std::shared_ptr<smallMap> map;

    std::shared_ptr<Notification> update_view_notification;
};
