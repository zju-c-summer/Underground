#include <QCoreApplication>
#include <QWidget>
#include <QPainter>
#include "./app/mazeapp.h"
#include <iostream>

int main(int argc, char *argv[])
{

    std::shared_ptr<mazeApp> a(new mazeApp(argc, argv));
    a->get_MainWindow()->show();
    a->processEvents();
    return a->exec();
}
