#ifndef _HORSE_WALK_H_
#define _HORSE_WALK_H_
#include <vector>
#include <iostream>

namespace chess 
{

#define table_size(t) sizeof(t)/sizeof(t[0])

struct coordinate 
{
    bool operator==(const coordinate &r) const {
        if (this->x == r.x && this->y == r.y)
            return true;
        return false;
    }

    void show() { std::cout << "[" << x << ", " << y << "]"; }

    short x;
    short y;
};

class chess_board 
{
public:
    chess_board(int x, int y);
    virtual ~chess_board() {};

    bool is_pos_visited(struct coordinate &pos) {
        return _pos_visited[pos.y * _size_x + pos.x];
    }

    void set_pos_visited(struct coordinate &pos) {
        _pos_visited[pos.y * _size_x + pos.x] = true;
    }

    void clear_pos_visited(struct coordinate &pos) {
        _pos_visited[pos.y * _size_x + pos.x] = false;
    }

    int size_col() { return _size_x; }
    int size_row() { return _size_y; }

private:
    chess_board();

private:
    int     _size_x;
    int     _size_y;

    std::vector<bool>   _pos_visited;
};


class chess_man 
{
public:
    chess_man();
    virtual ~chess_man();

    bool is_at_position(struct coordinate &pos);

    void set_pos(struct coordinate &pos) { _pos = pos; }

    virtual bool step_one(chess_board &board) = 0;

    struct coordinate& position() { return _pos; }

protected:
    struct coordinate   _pos;
};

class horse : public chess_man
{
public:
    horse() { }
    virtual ~horse() {};

    bool step_one(chess_board &board);
    
private:
    bool step_one(chess_board &board, const struct coordinate &offset);

private:
    const static struct coordinate _step_off[];
};

}

#endif