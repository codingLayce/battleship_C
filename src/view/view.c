#include "view.h"
#include "board_view.h"

void init_view(){
	initscr();
	cbreak();
	
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
