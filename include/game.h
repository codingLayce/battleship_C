#ifndef GAME_H_GUARD
#define GAME_H_GUARD

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "board.h"
#include "cell.h"
#include "player.h"
#include "boat.h"
#include "config.h"
#include "ncurses.h"
#include "view.h"

WINDOW *debug;

void main_loop(WINDOW *left, WINDOW *right);

void save(Player human, Player ia);
void load(Player *human, Player *ia, Cell human_board[BOARD_SIZE][BOARD_SIZE], Cell ia_board[BOARD_SIZE][BOARD_SIZE]);
#endif
