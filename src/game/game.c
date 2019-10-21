#include "game.h"

void main_loop(WINDOW *left_board, WINDOW *right_board) {
	Cell human_board[BOARD_SIZE][BOARD_SIZE], ia_board[BOARD_SIZE][BOARD_SIZE];
	Player human, ia;
	int turn = 0;
	char *win_message;

	player_factory(&human, HUMAN);
	player_factory(&ia, IA);

	new_board(human_board);
	new_board(ia_board);

	place_ia_boats(ia_board, &ia);
	print_board_without_boat(ia_board, left_board, "IA board");
	
	ask_player_to_place_boats(right_board, human_board, &human);
	print_board_with_boat(human_board, right_board, "Player board");

	do {
		human.play(left_board, ia_board, &human, &ia, turn);

		if (ia.boats_alive > 0) {
			ia.play(right_board, human_board, &human, &ia, turn);
		}
		
		print_board_with_boat(human_board, right_board, "Player board");
		turn++;
	} while (human.boats_alive > 0 && ia.boats_alive > 0);

	if (human.boats_alive <= 0) { /* IA win  */
		win_message = malloc(sizeof(char) * strlen("Victoire de l'IA !") + 1);
		strcpy(win_message, "Victoire de l'IA !");
	} else { /* Human win  */
		win_message = malloc(sizeof(char) * strlen("Victoire du joueur !") + 1);
		strcpy(win_message, "Victoire du joueur !");
	}
	
	create_centered_pop_up(win_message);	
	
	free(win_message);
	unload_player(&human);	
	unload_player(&ia);
}

