#include "board_view.h"

WINDOW *create_board_win(int start_row, int start_col, int height, int width){
	WINDOW *result =  newwin(height, width, start_row, start_col);
	wrefresh(result);
	return result;
}
