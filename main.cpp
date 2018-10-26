#include "path.h"

extern char *optarg;

static void usage(void)
{
    std::cout << "usage: ./horse_walk -c colnum -r rownum -x startx -y starty" << std::endl;
}

int main(int argc, char * argv[])
{
    int c, opt_flags = 0;
    int rows = 0, cols = 0;
    int start_x = 0, start_y = 0;

    while ((c = getopt(argc, argv, "c:r:x:y:")) != -1) {
        switch (c) {
        case 'c':
            cols = atoi(optarg);
            break;
        case 'r':
            rows = atoi(optarg);
            break;
        case 'x':
            start_x = atoi(optarg);
            break;
        case 'y':
            start_y = atoi(optarg);
            break;
        default:
            break;
        }
    }

    if (opt_flags != OPT_OK)
    
    std::vector<horse_path> paths;

    chess_board board(cols, rows);

    board.set_horse_pos(start_x, start_y);

    horse_path *p_path = nullptr;
    
    p_path = path_find(board, nullptr);
    while (p_path) {
        paths.push_back(*p_path);
        p_path = path_find(board, p_path);
    };

    return 0;
}