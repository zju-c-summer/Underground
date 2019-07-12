#include "mainwindow.h"
#include <QApplication>
//#include "maze.h"
int main(int argc,char* argv[ ])
{
    QApplication app(argc,argv);
    MainWindow w;
   // QWidget w;
    // 场景
   // QGraphicsScene *scene = new QGraphicsScene;
    // 矩形项
   // mazeModel *item = new mazeModel();
    // 项添加到场景
   // scene->addItem(item);
  //  scene
    // 视图
   // QGraphicsView *view = new QGraphicsView;
    //view->resize(1800,1800);
    // 视图关联场景
  //  view->move(-800,-800);
    //view->setScene(scene);
    // 显示视图

    w.show();
    app.processEvents();
    return app.exec();
}
