#ifndef BOARD_VIEW_H_GUARD
#define BOARD_VIEW_H_GUARD

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"

#define SEA_PAIR 1 
#define BOAT_PAIR 2
#define TOUCHED_SEA_PAIR 3
#define TOUCHED_BOAT_PAIR 4 
#define SELECTED_PAIR 5

WINDOW *create_board_win(int start_row, int start_col, int height, int width);

/* META function */
void print_board(Cell board[BOARD_SIZE][BOARD_SIZE], WINDOW *board_win, char *board_name, int print_boat, int selected_row, int selected_col);

void print_board_with_boat(Cell board[BOARD_SIZE][BOARD_SIZE], WINDOW *board_win, char *board_name);
void print_board_without_boat(Cell board[BOARD_SIZE][BOARD_SIZE], WINDOW *board_win, char *board_name);
void print_board_with_selection(Cell board[BOARD_SIZE][BOARD_SIZE], WINDOW *board_win, char *board_name, int selected_row, int selected_col);

char *get_coords(Cell board[BOARD_SIZE][BOARD_SIZE], WINDOW *board_win);
#endif
