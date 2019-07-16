#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include "../../utility/common/base.h"
#include "../../utility/common/common_value.h"
#include "../../utility/common/player.h"
#include "../../utility/common/block.h"

class game_control : public QGraphicsItem
{

public:
    game_control();
    ~game_control();
    QRectF boundingRect()const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void keyPress(int i);
    void bindMaze(std::shared_ptr<std::vector<std::vector<block> > > Maze);
    void bindPlayer(std::shared_ptr<player> Man);
    void bindMonster(std::shared_ptr<player> Mon);
    void bindDesc(std::shared_ptr<int> X,
    std::shared_ptr<int> Y);
    void bindSize(std::shared_ptr<std::size_t> row_size,
    std::shared_ptr<std::size_t> col_size);

    void set_move_command(std::shared_ptr<Command> command);
    void set_generate_command(std::shared_ptr<Command> command);
    void set_mons_flush_command(std::shared_ptr<Command> command);

    void mons_move();

protected:
    void playerGetTreasure();
    void playerGetExit();
    void playerMeetMonser();
    int judge();

private:

    int monsFlushTimer;

    std::shared_ptr<std::vector<std::vector<block> > > maze;
    std::shared_ptr<player> man;
    std::shared_ptr<int> des_x;
    std::shared_ptr<int> des_y;
    std::shared_ptr<player> mons;
    std::shared_ptr<std::size_t> row_size;
    std::shared_ptr<std::size_t> col_size;

    std::shared_ptr<Command> move_command;
    std::shared_ptr<Command> generate_command;
    std::shared_ptr<Command> mons_flush_command;
};

#endif // GAME_CONTROL_H
