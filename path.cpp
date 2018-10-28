#include "path.h"
#include "horse_walk.h"

#include <iostream>

using namespace chess;

horse_path::horse_path()
{
}

horse_path::~horse_path()
{
}

void horse_path::print_path()
{
    if (_path_coor.size() == 0) {
        std::cout << "No path" << std::endl;
    }

    unsigned int i;
    for (i = 0; i < _path_coor.size() - 1; i++) {
        std::cout << "[" << _path_coor[i].x << ", " << _path_coor[i].y << " ], ";
    }

    i = _path_coor.size() - 1;
    std::cout << "[" << _path_coor[i].x << ", " << _path_coor[i].y << " ]";
}
