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
}

void end_view(){
	endwin();
}
