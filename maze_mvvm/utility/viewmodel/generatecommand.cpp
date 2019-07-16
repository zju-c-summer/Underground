#include"generatecommand.h"
#include"mazeViewModel.h"

GenerateCommand::GenerateCommand(mazeViewModel *mvm):maze_viewmodel(mvm){}

void GenerateCommand::exec(){
    maze_viewmodel->exec_generate_command();
}

void GenerateCommand::setViewModel(mazeViewModel* VM){
    maze_viewmodel = VM;
}
