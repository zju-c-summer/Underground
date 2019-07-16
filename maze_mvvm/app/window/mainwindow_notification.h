#pragma once
//#include "mainwindow.h"
#include "../../utility/common/base.h"

class MainWindow;
class MainWindowNotification: public Notification{
private:
    std::shared_ptr<MainWindow> view;
public:
    void setView(std::shared_ptr<MainWindow> sv);
    virtual void exec();
};
