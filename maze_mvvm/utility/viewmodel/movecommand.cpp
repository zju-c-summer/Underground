#include "movecommand.h"
#include "mazeViewModel.h"


MoveCommand::MoveCommand(mazeViewModel *mvm):maze_viewmodel(mvm){}

void MoveCommand::exec(){
    std::string dir = static_pointer_cast<DirectionParameters,Parameters>(params)->get_Dir();
    maze_viewmodel->exec_move_command(dir);
}

void MoveCommand::setViewModel(mazeViewModel *VM){
    maze_viewmodel = VM;
}
