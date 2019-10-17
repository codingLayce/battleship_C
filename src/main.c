#include "view.h"
#include "board_view.h"
#include "board.h"

int main(){
	WINDOW *board_win;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	Boat cruiser;
	Boat boat;
	Boat to_place;
	Direction d = NORTH;

	init_view();

	boat_factory(&boat, CARRIER);
	new_board(board);

	boat_factory(&to_place, CARRIER);

	boat_factory(&cruiser, CRUISER);


/*	place_boat(board, &cruiser, 5, 5, NORTH); */
	
	
	
	
	place_boat(board, &boat, 5, 5, NORTH);
	/*board[4][4].touched = 1;
	board[6][5].touched = 1;*/

	board_win = create_board_win(0, 0, 50, 50);


	/*mvwprintw(board_win, 0, 0, "%d", check_if_boat_feets_in_board (board, boat, 0, 0, NORTH));*/



	
	board[5][5].touched = 1;
	
	printf("%s\n", ask_boat_position(board_win, to_place, &d));
/*
	print_board_without_boat(board, board_win, "test Board");

	selected = get_coords(board, board_win); 
	
	printf("%s\n", selected);
	free(selected);
*/	wrefresh(board_win);
	wgetch(board_win);

	delwin(board_win);

	end_view();	

	return 0;
}
