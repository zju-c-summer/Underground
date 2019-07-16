#pragma once

#include"../common/base.h"
//#include"mazeViewModel.h"

class mazeViewModel;

class EnemyFlushCommand: public Command{
private:
    mazeViewModel *maze_viewmodel;
public:

    EnemyFlushCommand(mazeViewModel *mvm);
    void exec();
    void setViewModel(mazeViewModel *VM);
};


