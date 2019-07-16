#include "mazeViewModel.h"
#include "movecommand.h"
#include "enemyflushcommand.h"

mazeViewModel:: mazeViewModel():maze(new std::vector<std::vector<block> >),
man(new player), des_x(new int), des_y(new int), mons(new player), row_size(new size_t), col_size(new size_t)
{
    move_command = std::static_pointer_cast<Command, MoveCommand>(std::shared_ptr<MoveCommand>(new MoveCommand(this)));
    enemy_flush_command = std::static_pointer_cast<Command, EnemyFlushCommand>(std::shared_ptr<EnemyFlushCommand>(new EnemyFlushCommand(this)));
    generate_command = std::static_pointer_cast<Command, GenerateCommand>(std::shared_ptr<GenerateCommand>(new GenerateCommand(this)));
    update_display_data_notification = std::static_pointer_cast<Notification, MazeViewModelNotification>
            (std::shared_ptr<MazeViewModelNotification>(new MazeViewModelNotification(this)));
    std::static_pointer_cast<MoveCommand, Command>(move_command)->setViewModel((this));
    std::static_pointer_cast<EnemyFlushCommand, Command>(enemy_flush_command)->setViewModel((this));
    std::static_pointer_cast<GenerateCommand, Command>(generate_command)->setViewModel((this));
    std::static_pointer_cast<MazeViewModelNotification, Notification>(update_display_data_notification)->setViewModel((this));
}


mazeViewModel::~mazeViewModel(){};

void mazeViewModel::bind(std::shared_ptr<maze_model> model){
    this->model = model;
}

void mazeViewModel::exec_move_command(std::string direction){
    if(direction == "Left") model->moveMan(0);
    else if(direction == "Right") model->moveMan(1);
    else if(direction == "Up") model->moveMan(2);
    else model->moveMan(3);
}

void mazeViewModel::exec_enemy_flush_command(){
    model->moveMonster(rand()%4);
}

void mazeViewModel::exec_generate_command(){
    model->generateMaze();
}

void mazeViewModel::set_update_view_notification(std::shared_ptr<Notification> notification){
    update_view_notification.push_back(notification);
}

std::shared_ptr<Command> mazeViewModel::get_move_command(){
    return move_command;
}

std::shared_ptr<Command> mazeViewModel::get_enemy_flush_command(){
    return enemy_flush_command;
}

std::shared_ptr<Command> mazeViewModel::get_generate_command(){
    return generate_command;
}

std::shared_ptr<Notification> mazeViewModel::get_update_display_data_notification(){
    return update_display_data_notification;
}

std::shared_ptr<std::vector<std::vector<block> > > mazeViewModel::get_maze(){
    return maze;
}

std::shared_ptr<player> mazeViewModel::get_man(){
    return man;
}

std::shared_ptr<int> mazeViewModel::get_des_x(){
    return des_x;
}

std::shared_ptr<int> mazeViewModel::get_des_y(){
    return des_y;
}

std::shared_ptr<player> mazeViewModel::get_mons(){
    return mons;
}

std::shared_ptr<std::size_t> mazeViewModel::get_row_size(){
    return row_size;
}

std::shared_ptr<std::size_t> mazeViewModel::get_col_size(){
    return col_size;
}

void mazeViewModel::notified(){
    *maze = model->get_maze();
    *man = model->get_man();
    *des_x = model->get_des_x();
    *des_y = model->get_des_y();
    *mons = model->get_monster();
    *row_size = model->get_row_size();
    *col_size = model->get_col_size();
    for(std::size_t i = 0; i < update_view_notification.size(); i++){
        update_view_notification[i]->exec();
    }
}

