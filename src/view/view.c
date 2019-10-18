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
/*
int create_pop_up (char *ask, char * choices[], int number){
	int start_row, start_col, height, width;
	int highlight = 0;
	int i;
	WINDOW *pop_win;

	height = 10;
	width = 20;

	start_col = (COLS - width);
	start_row = (LINES - height);

	pop_win =  newwin(height, width, start_row, start_col);
	
	wattron(popo_win, POP_UP_PAIR)
	wprintw(pop_win, "%s", ask);

	for (i = 0; i < number; i++){
		mvwprintw(pop_win, choices[i]);
	}
	
	wattroff(popo_win, POP_UP_PAIR);
	delwin(pop_win);

	return result;
}*/
