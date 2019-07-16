#include"enemyflushcommand.h"
#include"mazeViewModel.h"

EnemyFlushCommand::EnemyFlushCommand(mazeViewModel *mvm):maze_viewmodel(mvm){}

void EnemyFlushCommand::exec(){
    maze_viewmodel->exec_enemy_flush_command();
}

void EnemyFlushCommand::setViewModel(mazeViewModel* VM){
    maze_viewmodel = VM;
}
