#ifndef BOARD_VIEW_H_GUARD
#define BOARD_VIEW_H_GUARD

#include <ncurses.h>

WINDOW *create_board_win(int start_row, int start_col, int height, int width);

#endif
