#include "board_view.h"

WINDOW *create_board_win (int start_row, int start_col, int height, int width){
	WINDOW *result =  newwin(height, width, start_row, start_col);
	wrefresh(result);
	return result;
}

void print_board (Cell board[BOARD_SIZE][BOARD_SIZE], WINDOW *board_win, char *board_name){
	int row, col;
	int row_offset = 2, col_offset = 2;

	wprintw(board_win, board_name);

	/* horizontal help */
	for (col = 0; col < BOARD_SIZE; col++){
		mvwprintw(board_win, row_offset - 1, col * 2 + col_offset, "%d", col);
		mvwprintw(board_win, row_offset + BOARD_SIZE, col * 2 + col_offset, "%d", col);
	}

	/* Vertical help */
	for (row = 0; row < BOARD_SIZE; row++){
		mvwprintw(board_win, row + row_offset, 0, "%c", 65 + row);
		mvwprintw(board_win, row + row_offset, BOARD_SIZE * 2 + col_offset, "%c", 65 + row);
	}

	for (row = 0; row < BOARD_SIZE; row++){
		for (col = 0; col < BOARD_SIZE; col++){
			Cell c = board[row][col];
			if (c.boat == 0 && c.touched == 0){
				wattron(board_win, COLOR_PAIR(SEA_PAIR));
				mvwprintw(board_win, row + row_offset, col * 2 + col_offset, "~");
				wattroff(board_win, COLOR_PAIR(SEA_PAIR));
			} else if (c.boat == 0 && c.touched == 1){
				wattron(board_win, COLOR_PAIR(TOUCHED_SEA_PAIR));
				mvwprintw(board_win, row + row_offset, col * 2 + col_offset, "o");
				wattroff(board_win, COLOR_PAIR(TOUCHED_SEA_PAIR));
			} else if (c.boat != 0 && c.touched == 0){
				wattron(board_win, COLOR_PAIR(BOAT_PAIR));
				mvwprintw(board_win, row + row_offset, col * 2 + col_offset, "%c", c.boat->boat_char);
				wattroff(board_win, COLOR_PAIR(BOAT_PAIR));
			} else {
				wattron(board_win, COLOR_PAIR(TOUCHED_BOAT_PAIR));
				mvwprintw(board_win, row + row_offset, col * 2 + col_offset, "%c", c.boat->boat_char);
				wattroff(board_win, COLOR_PAIR(TOUCHED_BOAT_PAIR));
			}
			
		}
	}
	wrefresh(board_win);
}
