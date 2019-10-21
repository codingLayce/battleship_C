#include "view.h"
#include "board_view.h"

void init_view(){
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	if(has_colors() == FALSE){
		endwin();
		printf("No color\n");
		return ;
	}
	start_color();

	init_pair(SEA_PAIR, COLOR_BLUE, COLOR_BLACK);
	init_pair(BOAT_PAIR, COLOR_WHITE, COLOR_BLACK);
	init_pair(TOUCHED_SEA_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(TOUCHED_BOAT_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(SELECTED_PAIR, COLOR_BLACK, COLOR_WHITE);
	init_pair(POP_UP_PAIR, COLOR_BLACK, COLOR_WHITE);
	init_pair(SINK_BOAT_PAIR, COLOR_BLACK, COLOR_RED);

}

void end_view(){
	endwin();
}

void create_centered_pop_up (char *content){
	int start_row, start_col, height, width;
	WINDOW *pop_up;
	int row, col;
	height = 10;
	width = 40;
	
	start_col = (COLS / 2 - width);
	start_row = (LINES / 2 - height);

	pop_up = newwin(height, width, start_row, start_col);

	wattron(pop_up, COLOR_PAIR(POP_UP_PAIR));
	for (row = 0; row < height; row++){
		for (col = 0; col < width; col++){
			wprintw(pop_up, " ");
		}
	}
	
	mvwprintw(pop_up, 5, 5, "%s", content);
	wattroff(pop_up, COLOR_PAIR(POP_UP_PAIR));
	
	wrefresh(pop_up);
	wgetch(pop_up);
	wclear(pop_up);
	wrefresh(pop_up);
	delwin(pop_up);
}

int create_yes_no_pop_up(char *ask){
	int start_row, start_col, height, width;
	WINDOW *pop_up;
	int row, col;
	int selection = 1, ch;
	height = 10;
	width = 40;
	
	start_col = (COLS / 2 - width);
	start_row = (LINES / 2 - height);

	pop_up = newwin(height, width, start_row, start_col);

	wattron(pop_up, COLOR_PAIR(POP_UP_PAIR));
	for (row = 0; row < height; row++){
		for (col = 0; col < width; col++){
			wprintw(pop_up, " ");
		}
	}
	
	mvwprintw(pop_up, 5, 5, "%s", ask);
	wattroff(pop_up, COLOR_PAIR(POP_UP_PAIR));
do {
	if (selection == 0)
		wattron(pop_up, A_REVERSE);
	mvwprintw(pop_up, 7, 3, "NON");
	wattroff(pop_up, A_REVERSE);

	if (selection == 1)
		wattron(pop_up, A_REVERSE);
	mvwprintw(pop_up, 7, width - 6, "OUI");
	wattroff(pop_up, A_REVERSE);
	
	ch = wgetch(pop_up);

	if (ch == 'q' && selection < 1)
		selection++; 
	if (ch == 'd' && selection > 0)
		selection--;
} while (ch != '\n');

	wattroff(pop_up, A_REVERSE);

	wrefresh(pop_up);
	delwin(pop_up);
	return selection;
}
