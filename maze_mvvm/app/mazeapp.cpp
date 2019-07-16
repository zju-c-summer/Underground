#pragma once
#include"mazeapp.h"

mazeApp::mazeApp(int argc, char* argv[]):QApplication(argc, argv),
    MW(new MainWindow), mazeM(new maze_model), mazeVM(new mazeViewModel)
{
    mazeVM->bind(mazeM);
    mazeM->set_update_display_data_notification(mazeVM->get_update_display_data_notification());
    mazeVM->set_update_view_notification(MW->get_view_notification());
    MW->get_viewer()->get_control().set_move_command(mazeVM->get_move_command());
    MW->get_viewer()->get_control().set_generate_command(mazeVM->get_generate_command());
    MW->get_viewer()->get_control().set_mons_flush_command(mazeVM->get_enemy_flush_command());
    MW->get_viewer()->get_control().bindDesc(mazeVM->get_des_x(), mazeVM->get_des_y());
    MW->get_viewer()->get_control().bindMaze(mazeVM->get_maze());
    MW->get_viewer()->get_control().bindPlayer(mazeVM->get_man());
    MW->get_viewer()->get_control().bindMonster(mazeVM->get_mons());
    MW->get_viewer()->get_control().bindSize(mazeVM->get_row_size(), mazeVM->get_col_size());
    MW->get_smallMap()->bindDesc(mazeVM->get_des_x(), mazeVM->get_des_y());
    MW->get_smallMap()->bindPlayer(mazeVM->get_man());
}

shared_ptr<MainWindow> mazeApp::get_MainWindow(){
    return MW;
}
