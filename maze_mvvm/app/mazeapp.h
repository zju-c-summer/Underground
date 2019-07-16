#pragma once

#include"../utility/common/base.h"
#include"../utility/common/common_value.h"
#include"../utility/model/maze_model.h"
#include"../utility/viewmodel/mazeViewModel.h"
#include"./window/mainwindow.h"
//#include"mazeapp.cpp"
#include <QApplication>

class mazeApp: public QApplication{
private:
    std::shared_ptr<MainWindow> MW;
    std::shared_ptr<maze_model> mazeM;
    std::shared_ptr<mazeViewModel> mazeVM;
public:
    mazeApp(int argc, char *argv[]);
    shared_ptr<MainWindow> get_MainWindow();
};

