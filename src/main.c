#include "view.h"
#include "board_view.h"
#include "game.h"

int main(){
	WINDOW *left_board, *right_board;

	init_view();
	left_board = create_board_win(0, 0, 25, 25);
	right_board = create_board_win(0, 30, 25, 25);


	main_loop(left_board, right_board);

	wrefresh(left_board);
	wrefresh(right_board);
	wgetch(left_board);
	delwin(left_board);
	delwin(right_board);

	end_view();	

	return 0;
}
