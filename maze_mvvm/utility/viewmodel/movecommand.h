#pragma once

#include"../common/base.h"
//#include"mazeViewModel.h"

class mazeViewModel;
class MoveCommand: public Command{
private:
    mazeViewModel* maze_viewmodel;
public:

    MoveCommand(mazeViewModel *mvm);
    void exec();
    void setViewModel(mazeViewModel *VM);
};

