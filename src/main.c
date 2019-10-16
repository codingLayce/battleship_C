#include "view.h"
#include "board_view.h"
#include "board.h"

int main(){
	WINDOW *board_win;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	Boat boat;

	init_view();

	boat_factory(&boat, BATTLESHIP);
	new_board(board);

	place_boat(board, &boat, 5, 5, NORTH);
	board[4][4].touched = 1;
	board[6][5].touched = 1;

	board_win = create_board_win(0, 0, 50, 50);

	print_board(board, board_win, "test Board");

	wrefresh(board_win);
	wgetch(board_win);

	delwin(board_win);

	end_view();	

	return 0;
}
