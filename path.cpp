#include "path.h"
#include "horse_walk.h"

horse_path::horse_path()
{
}

horse_path::~horse_path()
{
}

inline void horse_path::push_pos(struct coordinate &x)
{
    _path_coor.push_back(x);
}

inline void horse_path::pop_latest_pos()
{
    _path_coor.pop_back();
}
