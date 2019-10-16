#ifndef BOARD_VIEW_H_GUARD
#define BOARD_VIEW_H_GUARD

#include <ncurses.h>
#include <string.h>

#include "board.h"

#define SEA_PAIR 1 
#define BOAT_PAIR 2
#define TOUCHED_SEA_PAIR 3
#define TOUCHED_BOAT_PAIR 4 


WINDOW *create_board_win(int start_row, int start_col, int height, int width);
void print_board(Cell board[BOARD_SIZE][BOARD_SIZE], WINDOW *board_win, char *board_name);

#endif
