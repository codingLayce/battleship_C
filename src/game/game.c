#include "game.h"

void main_loop(WINDOW *win) {
	Cell human_board[BOARD_SIZE][BOARD_SIZE], ia_board[BOARD_SIZE][BOARD_SIZE];
	Player human, ia, *current;

	player_factory(&human, HUMAN);
	player_factory(&ia, IA);

	new_board(human_board);
	new_board(ia_board);

	ask_player_to_place_boats(win, human_board, &human);

	print_board_with_boat(human_board, win, "Human board");
}

