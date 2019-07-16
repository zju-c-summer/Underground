#pragma once

#include"../common/base.h"
//#include"mazeViewModel.h"

class mazeViewModel;
class GenerateCommand: public Command{
private:
    mazeViewModel* maze_viewmodel;
public:

    GenerateCommand(mazeViewModel *mvm);
    void exec();
    void setViewModel(mazeViewModel* VM);
};
