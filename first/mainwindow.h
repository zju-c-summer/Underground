#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
