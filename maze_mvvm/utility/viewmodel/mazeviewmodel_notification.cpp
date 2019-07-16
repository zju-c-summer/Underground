#include"mazeviewmodel_notification.h"
#include"mazeViewModel.h"

MazeViewModelNotification::MazeViewModelNotification(mazeViewModel* vm):maze_viewmodel(vm){}

void MazeViewModelNotification::exec(){
    cout << "ook" << endl;
    maze_viewmodel->notified();
}

void MazeViewModelNotification::setViewModel(mazeViewModel* VM){
    maze_viewmodel = VM;
}
