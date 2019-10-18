#include "view.h"
#include "board_view.h"
#include "game.h"

int main(){
	WINDOW *board_win;

	init_view();
	board_win = create_board_win(0, 0, 50, 50);

	main_loop(board_win);

	wrefresh(board_win);
	wgetch(board_win);
	delwin(board_win);

	end_view();	

	return 0;
}
