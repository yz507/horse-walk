#include "path.h"

#include <unistd.h>

#include <iostream>

using namespace chess;

#define OPT_OK  0x0F
extern char *optarg;


static void usage(void)
{
    std::cout << "usage: ./horse_walk -c colnum -r rownum -x startx -y starty" << std::endl;
}

void display_path(std::vector<horse_path *> &paths)
{
    if (paths.size() == 0) {
        std::cout << "path not found" << std::endl;
        return;
    }

    for (unsigned i = 0; i < paths.size(); i++) {
        std::cout << "The " << i << " path is: " << std::endl;
        paths[i]->print_path();
        std::cout << std::endl;
    }
}


bool horse_walk_on_board(chess_board &board, horse &ahorse,
                         horse_path *p_path, struct coordinate &dst)
{
    bool success;

    success = ahorse.step_one(board);
    if (!success) {
        if (p_path->empty()) {
            std::cout << "path empty, can not back" << std::endl;
            return false;
        }

        p_path->pop_latest_pos();

        ahorse.set_pos(p_path->last_pos());

        return horse_walk_on_board(board, ahorse, p_path, dst);
    } else if (ahorse.is_at_position(dst)) {
        p_path->push_pos(dst);
        std::cout << "congradulations, find one path...." << std::endl;
        return true;
    }

    p_path->push_pos(ahorse.position());

    if (board.is_pos_visited(dst)) 
        board.clear_pos_visited(dst);

    return horse_walk_on_board(board, ahorse, p_path, dst);
}

horse_path* path_find(chess_board &board, horse &ahorse,
                horse_path *p_path_base, struct coordinate &dst)
{
    horse_path *p_path;

    p_path = new(std::nothrow)horse_path();
    if (p_path == nullptr) {
        std::cout << "out of memory" << std::endl;
        return nullptr;
    }
    
    if (p_path_base) {
        *p_path = *p_path_base;
        if (p_path->last_pos() == dst) {
            p_path->pop_latest_pos();
            ahorse.set_pos(p_path->last_pos());
        }
    } else {
        p_path->push_pos(ahorse.position());
    }
    
    if (horse_walk_on_board(board, ahorse, p_path, dst))
        return p_path;
    
    delete p_path;

    return nullptr;
}

int main(int argc, char * argv[])
{
    int c, opt_flags = 0;
    int rows = 0, cols = 0;
    struct coordinate start_pos;
    struct coordinate dest;

    while ((c = getopt(argc, argv, "c:r:x:y:")) != -1) {
        switch (c) {
        case 'c':
            cols = atoi(optarg);
            opt_flags |= 0x1;
            break;
        case 'r':
            rows = atoi(optarg);
            opt_flags |= 0x2;
            break;
        case 'x':
            start_pos.x = atoi(optarg);
            opt_flags |= 0x4;
            break;
        case 'y':
            start_pos.y = atoi(optarg);
            opt_flags |= 0x8;
            break;
        default:
            break;
        }
    }

    if (opt_flags != OPT_OK) {
        std::cout << "error parameters" << std::endl;
        usage();
        return -1;
    } else if (start_pos.y > cols || start_pos.x > rows ||
        (start_pos.y | start_pos.x | cols | rows) < 0) {
        std::cout << "error parameters" << std::endl;
        return -1;
    }

    std::cout << "Input dest o x:";
    std::cin >> dest.x;
    std::cout << "Input dest o y:";
    std::cin >> dest.y;
    if (dest.x > rows || dest.y > cols || (dest.x | dest.y) < 0) {
        std::cout << "error parameters" << std::endl;
        return -1;
    }
    
    std::vector<horse_path *> paths;

    chess_board board(cols, rows);

    horse ahorse;

    ahorse.set_pos(start_pos);
    board.set_pos_visited(start_pos);

    horse_path *p_path = nullptr, *p_path1;
    
    p_path1 = p_path = path_find(board, ahorse, nullptr, dest);
    while (p_path) {
        paths.push_back(p_path);
        p_path = path_find(board, ahorse, p_path1, dest);
    }

    //display_path(paths);

    return 0;
}