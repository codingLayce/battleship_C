#ifndef GAME_H_GUARD
#define GAME_H_GUARD

#include <string.h>
#include "board.h"
#include "cell.h"
#include "player.h"
#include "boat.h"
#include "config.h"
#include "ncurses.h"
#include "view.h"

void main_loop(WINDOW *left, WINDOW *right);

void fwrite_board(Cell board[BOARD_SIZE][BOARD_SIZE], FILE *savefile);
void save(Player human, Player ia, Cell humanboard[BOARD_SIZE][BOARD_SIZE], Cell ia_board[BOARD_SIZE][BOARD_SIZE]);
#endif
