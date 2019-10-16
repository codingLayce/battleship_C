#include <stdlib.h>
#include "player.h"

void player_factory(Player *player, Player_type type){
	switch (type) {
		case IA:
			new_player(player, 0, NULL);
			break;
		case HUMAN:
			new_player(player, 0, NULL);
			break;
		default:
			player = NULL;
			break;
	}
}

void new_player (Player *player, int boats_alive, void (*play)(Cell board[BOARD_SIZE][BOARD_SIZE])){
	player->boats_alive = boats_alive;
	player->play = play;
}

