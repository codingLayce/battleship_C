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

void hit (Cell *cell, Player *hit_player) {
	hit_cell(cell);
	
	if (cell->boat != NULL) {
		cell->boat->hits++;

		if (cell->boat->size == cell->boat->hits) { /* If boat destroyed  */
			hit_player->boats_alive--;	
		}
	}
}

void ask_player_to_place_boats(WINDOW *win, Cell board[BOARD_SIZE][BOARD_SIZE], Player *player) {
	Boat carrier, battleship, cruiser, submarine, destroyer; 
	
	boat_factory(&carrier, CARRIER);
	boat_factory(&battleship, BATTLESHIP);
	boat_factory(&cruiser, CRUISER);
	boat_factory(&submarine, SUBMARINE);
	boat_factory(&destroyer, DESTROYER);
	
		
	ask_player_to_place_one_boat(win, board, player, &carrier);	
	ask_player_to_place_one_boat(win, board, player, &battleship);	
	ask_player_to_place_one_boat(win, board, player, &cruiser);	
	ask_player_to_place_one_boat(win, board, player, &submarine);	
	ask_player_to_place_one_boat(win, board, player, &destroyer);	
}

void ask_player_to_place_one_boat(WINDOW *win, Cell board[BOARD_SIZE][BOARD_SIZE], Player *player, Boat *boat) {
	Direction direction;
	int row, col;
	char *starting_position = malloc(sizeof(char) * 3);;

	do {
		starting_position = ask_boat_position(win, *boat, &direction);

		row = starting_position[0] - 'A';
		col = starting_position[1] - '0';
	} while (check_if_boat_feets_in_board(board, *boat, row, col, direction) == 0);
	
	free(starting_position);
	
	place_boat(board, boat, row, col, direction);
	player->boats_alive++;
}
