#ifndef PLAYER_H_GUARD
#define PLAYER_H_GUARD

#include "../cell/cell.h"
#include "../../etc/config.h"

typedef enum {HUMAN, IA} Player_type;

typedef struct {
	int boats_alive;
	void (*play)(Cell board[BOARD_SIZE][BOARD_SIZE]);
} Player;

void player_factory(Player *player, Player_type type);

void new_player(Player *player, int boats_alive, void (*play)(Cell board[BOARD_SIZE][BOARD_SIZE]);

#endif
