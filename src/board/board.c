#include <stdlib.h>
#include "board.h"

void new_board (Cell board[BOARD_SIZE][BOARD_SIZE]) {
	int row, col;

	for (row = 0; row < BOARD_SIZE; row++) {
		for (col = 0; col < BOARD_SIZE; col++) {
			Cell c;
			new_cell(&c, NULL, 0);
			board[row][col] = c;
		}
	}
}
