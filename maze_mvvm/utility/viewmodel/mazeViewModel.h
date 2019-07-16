#pragma once
#include "../model/maze_model.h"
#include "../common/base.h"
#include "enemyflushcommand.h"
#include "movecommand.h"
#include "mazeviewmodel_notification.h"
#include "generatecommand.h"
#include <vector>

class mazeViewModel
{
private:

    std::shared_ptr<std::vector<std::vector<block> > > maze;
    std::shared_ptr<player> man;
    std::shared_ptr<int> des_x;
    std::shared_ptr<int> des_y;
    std::shared_ptr<player> mons;
    std::shared_ptr<std::size_t> row_size;
    std::shared_ptr<std::size_t> col_size;

    std::shared_ptr<maze_model> model;


    std::shared_ptr<Command> move_command;
    std::shared_ptr<Command> enemy_flush_command;
    std::shared_ptr<Command> generate_command;


    std::shared_ptr<Notification> update_display_data_notification;

    vector<std::shared_ptr<Notification> > update_view_notification;

public:
    mazeViewModel();
    ~mazeViewModel();
    void bind(std::shared_ptr<maze_model> model);
    void exec_move_command(std::string direction);
    void exec_enemy_flush_command();
    void exec_generate_command();

    void set_update_view_notification(std::shared_ptr<Notification> notification);

    std::shared_ptr<Command> get_move_command();
    std::shared_ptr<Command> get_enemy_flush_command();
    std::shared_ptr<Command> get_generate_command();

    std::shared_ptr<std::vector<std::vector<block> > > get_maze();
    std::shared_ptr<player> get_man();
    std::shared_ptr<int> get_des_x();
    std::shared_ptr<int> get_des_y();
    std::shared_ptr<player> get_mons();
    std::shared_ptr<std::size_t> get_row_size();
    std::shared_ptr<std::size_t> get_col_size();

    std::shared_ptr<Notification> get_update_display_data_notification();

    void notified();
};
