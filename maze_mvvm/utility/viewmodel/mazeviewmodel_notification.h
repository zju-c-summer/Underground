#pragma once

#include"../common/base.h"
//#include"mazeViewModel.h"

class mazeViewModel;
class MazeViewModelNotification: public Notification{
private:
    mazeViewModel* maze_viewmodel;
public:
    MazeViewModelNotification(mazeViewModel* vm);
    void exec();
    void setViewModel(mazeViewModel* VM);
};



