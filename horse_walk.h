#ifndef _HORSE_WALK_H_
#define _HORSE_WALK_H_

struct coordinate {
    int x;
    int y;
};

class chess_man {
public:
    chess_man();
    virtual ~chess_man();

    bool is_at_position(struct coordinate &pos);

    virtual void move_next(struct coordinate &offset);

private:
    struct coordinate   _pos;
};

class horse {
public:
    horse();
    virtual ~horse();

    void move_next(struct coordinate &offset);


private:
    struct coordinate   _pos;
};

class chess_board {
public:
    chess_board();
    virtual ~chess_board();

private:
    chess_man   _horse;

private:
    int     _size_x;
    int     _size_y;
};

#endif