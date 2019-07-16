#include"mainwindow_notification.h"
#include"mainwindow.h"

void MainWindowNotification::setView(std::shared_ptr<MainWindow> sv){
    view = sv;
}
void MainWindowNotification::exec(){
    view->update();
    view->get_viewer()->update();
    view->get_smallMap()->update();
}
