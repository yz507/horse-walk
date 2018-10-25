#ifndef _HORSE_PATH_H_
#define _HORSE_PATH_H_
#include <vector>

namespace chess
{

class horse_path
{
public:
    horse_path();
    virtual ~horse_path();

    void push_pos(struct coordinate &x);
    void pop_latest_pos();

private:
    std::vector<struct coordinate> _path_coor;
};

}
#endif