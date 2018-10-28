#ifndef _HORSE_PATH_H_
#define _HORSE_PATH_H_
#include "horse_walk.h"

#include <vector>

namespace chess
{

class horse_path
{
public:
    horse_path();
    virtual ~horse_path();

    void push_pos(struct coordinate &x) {
        std::cout << "push position ";
        x.show();
        std::cout << std::endl;

        _path_coor.push_back(x);
    }
    
    void pop_latest_pos() { 
        std::cout << "pop position ";
        _path_coor.back().show();
        std::cout << std::endl;
        _path_coor.pop_back();
    }

    struct coordinate &last_pos() { return _path_coor.back(); }
    
    bool empty() {
        return _path_coor.size() == 0; 
    }

    //horse_path & operator=(const horse_path &);
    void print_path();

private:
    std::vector<struct coordinate> _path_coor;
};

}
#endif