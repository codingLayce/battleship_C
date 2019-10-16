#include "view.h"
#include "board_view.h"
#include "board.h"

int main(){
	WINDOW *board_win;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	char *selected;
	Boat cruiser;
	Boat boat;

	init_view();

	boat_factory(&boat, BATTLESHIP);
	new_board(board);

	boat_factory(&cruiser, CRUISER);
	place_boat(board, &cruiser, 5, 5, NORTH);
	place_boat(board, &boat, 5, 5, NORTH);
	board[4][4].touched = 1;
	board[6][5].touched = 1;

	board_win = create_board_win(0, 0, 50, 50);
	
	board[5][5].touched = 1;

	print_board_without_boat(board, board_win, "test Board");

	selected = get_coords(board, board_win); 
	
	printf("%s\n", selected);
	free(selected);
	wrefresh(board_win);
	wgetch(board_win);

	delwin(board_win);

	end_view();	

	return 0;
}
