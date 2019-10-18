#ifndef GAME_H_GUARD
#define GAME_H_GUARD

#include "board.h"
#include "cell.h"
#include "player.h"
#include "boat.h"
#include "config.h"
#include "ncurses.h"

void main_loop(WINDOW *left, WINDOW *right);

#endif
