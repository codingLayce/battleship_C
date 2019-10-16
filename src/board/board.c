#include <stdlib.h>
#include "cell.h"
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

int check_if_boat_feets_in_board(Cell board[BOARD_SIZE][BOARD_SIZE], Boat boat, int row, int col, Direction direction) {
	switch (direction) {
		case SOUTH: /* Back of the boat goes to NORTH  */
			return (row - boat.size >= 0);
		case WEST: /* Back of the boat goes to EAST  */	
			return (col + boat.size < BOARD_SIZE);
		case NORTH: /* Back of the boat goes to SOUTH  */
			return (row + boat.size < BOARD_SIZE);
		case EAST: /* Back of the boat goes to WEST  */
			return (col - boat.size >= 0);
		default:
			return 0;
	}
}

void place_boat (Cell board[BOARD_SIZE][BOARD_SIZE], Boat *boat, int row, int col, Direction direction) {
	int i;
	switch (direction) {
		case SOUTH:
			for (i = row; i > row - boat->size; i--) {
				set_boat(&board[i][col], boat);
			}
			break;
		case WEST:
			for (i = col; i < col + boat->size; i++) {
				set_boat(&board[row][i], boat);
			}
			break;
		case NORTH:
			for (i = row; i < row + boat->size; i++) {
				set_boat(&board[i][col], boat);
			}
			break;
		case EAST:
			for (i = col; i > col - boat->size; i--) {
				set_boat(&board[row][i], boat);
			}
			break;
	}
}
