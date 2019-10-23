#include "game.h"

/* Global variables because without we can't save when receiving the SIGINT signal  */
Cell human_board[BOARD_SIZE][BOARD_SIZE], ia_board[BOARD_SIZE][BOARD_SIZE];
Player human, ia;

void on_signal_reception (int sig) {
	int res;

	if (sig == SIGINT) {	
		res = create_yes_no_pop_up("Voulez-vous sauvegarder ?");
		end_view();
		if (res == 0) {
			save(human, ia);	
			printf("Game saved !\n");
		}

		sleep(2);
		exit(1);
	}
}

void main_loop(WINDOW *left_board, WINDOW *right_board) {
	int turn = 0;
	char *win_message;
	FILE *savefile;

	player_factory(&human, HUMAN);
	player_factory(&ia, IA);

	new_board(human_board);
	new_board(ia_board);
	
	savefile = fopen("game.save", "r");
	if (savefile != NULL) {
		int res;
		res = create_yes_no_pop_up("Voulez-vous reprendre votre partie ?");

		if (res == 0) {
			load(&human, &ia, human_board, ia_board);
		} else {	
			place_ia_boats(ia_board, &ia);
			print_board_without_boat(ia_board, left_board, "IA board");

			ask_player_to_place_boats(right_board, human_board, &human);
			print_board_with_boat(human_board, right_board, "Player board");
		}

		fclose(savefile);
		remove("game.save");
	} else {
		place_ia_boats(ia_board, &ia);
		print_board_without_boat(ia_board, left_board, "IA board");

		ask_player_to_place_boats(right_board, human_board, &human);
		print_board_with_boat(human_board, right_board, "Player board");
	}
		
	signal(SIGINT, on_signal_reception);

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

void save(Player human, Player ia){
	char filename[] = "game.save";
	FILE *savefile;
	int i;

	savefile = fopen(filename, "w+");
	
	for (i = 0; i < 5; i++) {
		fwrite(human.boats[i], sizeof(Boat), 1, savefile);
		fwrite(ia.boats[i], sizeof(Boat), 1, savefile);
	}
	for (i = 0; i < 100; i++) {
		fwrite(human.history[i], sizeof(char) * 2, 1, savefile);
		fwrite(ia.history[i], sizeof(char) * 2, 1, savefile);
	}

	fclose(savefile);
}

void load(Player *human, Player *ia, Cell human_board[BOARD_SIZE][BOARD_SIZE], Cell ia_board[BOARD_SIZE][BOARD_SIZE]) {
	int i, row, col;
	char shot[3];
	char filename[] = "game.save";
	FILE *savefile = fopen(filename, "w+");
	savefile = fopen(filename, "w+");

	if (savefile == NULL) {
		return;
	}

	for (i = 0; i < 5; i++){
		Boat *ia_boat = ia->boats[i], *human_boat = human->boats[i];
		fread(human_boat, sizeof(Boat), 1, savefile);
		fread(ia_boat, sizeof(Boat), 1, savefile);
		place_boat(human_board, human_boat, human_boat->start_row, human_boat->start_col, human_boat->direction);
		place_boat(ia_board, ia_boat, ia_boat->start_row, ia_boat->start_col, ia_boat->direction);
	}

	for (i = 0; i < 100; i++){
		fread(shot, sizeof(char), 2, savefile);
		if (shot[0] != '-'){
			row = shot[0] - 'A';
			col = shot[1] - '0';
			hit(&ia_board[row][col], ia);
		}

		fread(shot, sizeof(char), 2, savefile);
		if (shot[0] != '-'){
			row = shot[0] - 'A';
			col = shot[1] - '0';
			hit(&human_board[row][col], human);
		}
	}

	fclose(savefile);
}
