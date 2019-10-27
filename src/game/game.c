#include "game.h"

/* Global variables because without we can't save when receiving the SIGINT signal  */
Cell human_board[BOARD_SIZE][BOARD_SIZE], ia_board[BOARD_SIZE][BOARD_SIZE];
Player *pt_human, *pt_ia;

void on_signal_reception (int sig) {
	int res;

	if (sig == SIGINT) {	
		res = create_yes_no_pop_up("Voulez-vous sauvegarder ?");
		end_view();
		if (res == 0) {
			save(*pt_human, *pt_ia);	
			printf("Game saved !\n");
		}

		exit(1);
	}
}

void main_loop(WINDOW *left_board, WINDOW *right_board) {
	int turn = 0;
	char *win_message;
	FILE *savefile;
	Player human, ia;

	pt_human = &human;
	pt_ia = &ia;

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

			ask_player_to_place_boats(right_board, human_board, &human);
		}
		print_board_without_boat(ia_board, left_board, "IA board");
		print_board_with_boat(human_board, right_board, "Player board");

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
		fprintf(savefile, "%c %d %d %d %d\n", human.boats[i]->boat_char, human.boats[i]->size, human.boats[i]->start_row, human.boats[i]->start_col, human.boats[i]->direction);
		fprintf(savefile, "%c %d %d %d %d\n", ia.boats[i]->boat_char, ia.boats[i]->size, ia.boats[i]->start_row, ia.boats[i]->start_col, ia.boats[i]->direction);
		/*fwrite(human.boats[i], sizeof(Boat), 1, savefile);
		fwrite(ia.boats[i], sizeof(Boat), 1, savefile);*/
	}
	for (i = 0; i < 100; i++) {
		fprintf(savefile, "%c %c\n", human.history[i][0], human.history[i][1]);
		fprintf(savefile, "%c %c\n", ia.history[i][0], ia.history[i][1]);

		/*fwrite(human.history[i], sizeof(char), 2, savefile);
		fwrite(ia.history[i], sizeof(char), 2, savefile);*/
	}

	fclose(savefile);
}

void load(Player *human, Player *ia, Cell human_board[BOARD_SIZE][BOARD_SIZE], Cell ia_board[BOARD_SIZE][BOARD_SIZE]) {
	int i, row, col;
	char filename[] = "game.save";
	FILE *savefile;

	savefile = fopen(filename, "r");
	if (savefile == NULL) {
		return;
	}

	for (i = 0; i < 5; i++){
		int d;
		Boat b, b2;

		fscanf(savefile, "%c %d %d %d %d\n", &b.boat_char, &b.size, &b.start_row, &b.start_col, &d);
		b.direction = (Direction)d;	
		new_boat(human->boats[i], b.boat_char, b.size, 0, b.start_row, b.start_col, b.direction);
		place_boat(human_board, human->boats[i], human->boats[i]->start_row, human->boats[i]->start_col, human->boats[i]->direction);
		
		fscanf(savefile, "%c %d %d %d %d\n", &b2.boat_char, &b2.size, &b2.start_row, &b2.start_col, &d);
		b2.direction = (Direction)d;	
		new_boat(ia->boats[i], b2.boat_char, b2.size, 0, b2.start_row, b2.start_col, b2.direction);
		place_boat(ia_board, ia->boats[i], ia->boats[i]->start_row, ia->boats[i]->start_col, ia->boats[i]->direction);
	}
	human->boats_alive = 5;
	ia->boats_alive = 5;
	for (i = 0; i < 10; i++){
		char tmp, tmp2;

		fscanf(savefile, "%c %c\n", &tmp, &tmp2);

		if (tmp2 != '-'){
			row = (int) tmp - 'A';
			col = (int) tmp2 - '0';
			hit(&ia_board[row][col], human);
		}


		fscanf(savefile, "%c %c\n", &tmp, &tmp2);

		if (tmp2 != '-'){
			row = (int) tmp - 'A';
			col = (int) tmp2 - '0';
			hit(&human_board[row][col], ia);
		}

	}

	fclose(savefile);
}
