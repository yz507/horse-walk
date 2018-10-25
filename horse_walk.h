#ifndef _HORSE_WALK_H_
#define _HORSE_WALK_H_
#include <vector>

namespace chess 
{
struct coordinate 
{
    short x;
    short y;
};

class chess_man 
{
public:
    chess_man();
    virtual ~chess_man();

    bool is_at_position(struct coordinate &pos);

    virtual void move_next() = 0;

    inline struct coordinate& get_current_pos() { return _pos; }

protected:
    struct coordinate   _pos;
};

class horse : public chess_man
{
public:
    horse() { _pos.x = _pos.y = 0; }
    virtual ~horse();

    inline void move_next();
    inline void set_pos(int x, int y) { _pos.x = x; _pos.y = y; }
};

class chess_board 
{
public:
    chess_board();
    virtual ~chess_board();

    bool initialize(int x, int y);

    void set_horse_pos(int x, int y);
    bool horse_step_one();

private:
    chess_man   *_horse;

private:
    int     _size_x;
    int     _size_y;

    std::vector<bool>   _pos_visited;
};

}

#endif