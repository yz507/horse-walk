#include <iostream>

#include "horse_walk.h"

using namespace chess;

//chess_man
chess_man::chess_man() : _pos({0,0})
{
}

chess_man::~chess_man()
{
}

bool chess_man::is_at_position(struct coordinate &pos)
{
    return pos == _pos;
}
//horse

void horse::move_next(int offx, int offy)
{
    _pos.x += offx;
    _pos.y += offy;
}

//chess board
chess_board::chess_board() : _size_x(0), _size_y(0), _horse(nullptr)
{
}

chess_board::~chess_board()
{
    if (_horse) 
        delete _horse;
    
    _horse = nullptr;
}

void chess_board::set_horse_pos(int x, int y)
{
    _horse->set_pos(x, y);
}

bool chess_board::initialize()
{
    _coor_visited.resize(x * y);

    //todo: set false

    _horse = new(std::nothrow) horse();
    if (!_horse) {
        std::cout << "Fail to initialize chess board - out of memory" << std::endl;
        return false;
    }

    return true;
}

bool chess_board::horse_step_one(int off_x, int off_y)
{
    struct coordinate &horse_pos_cur = _horse->get_current_pos();
    
    int n = _horse_pos_cur.x + off_x;

    if (n >= _size_x || n < 0)
        return false;
    
    n = _horse_pos_cur.y + off_y;
    if (n > _size_y || n < 0)
        return false;
    
    if (_pos_visited[off_y * _size_x + off_x] == true)
        return false;
    
    _horse->set_horse_pos(off_x, off_y);
    _pos_visited[off_y * _size_x + off_x] = true;

    return true;
}

