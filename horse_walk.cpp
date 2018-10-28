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

const struct coordinate horse::_step_off[] = {
        {  1,  2 },
        {  2,  1 },
        {  2, -1 },
        {  1, -2 },
        { -1, -2 },
        { -2, -1 },
        { -2,  1 },
        { -1,  2 }
    };

bool horse::step_one(chess_board &board, const struct coordinate &offset)
{
    struct coordinate new_pos;

    new_pos.x = _pos.x + offset.x;

    if (new_pos.x >= board.size_col() || new_pos.x < 0)
        return false;
    
    new_pos.y = _pos.y + offset.y;
    if (new_pos.y >= board.size_row() || new_pos.y < 0)
        return false;
    
    if (board.is_pos_visited(new_pos))
        return false;

    set_pos(new_pos);
    board.set_pos_visited(new_pos);

    return true;
}

bool horse::step_one(chess_board &board)
{
    for (unsigned i = 0; i < table_size(_step_off); i++) {
        if (step_one(board, _step_off[i]))
            return true;
    }

    return false;
}

//chess board
chess_board::chess_board() : _size_x(0), _size_y(0)
{
}

chess_board::chess_board(int x, int y) : _size_x(x), _size_y(y) 
{
    _pos_visited = std::vector<bool>(x * y, false);
}

