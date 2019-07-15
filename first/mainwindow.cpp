#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());

   // initcharacter();
    initwidget();
}

void MainWindow::initwidget()
{
    //初始化界面控件
    surface = new interface(this);
    surface->hide();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    switch (QMessageBox::information(this,tr("exit tip"),tr("Do you really want to exit?"),tr("Yes"),tr("No"),0,1))
    {
    case 0:
        event->accept();
        break;
    case 1:
    default:
        event->ignore();
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

