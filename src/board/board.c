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
	int i;
	switch (direction) {
		case SOUTH: /* Back of the boat goes to NORTH  */
			if (row + 1 - boat.size >= 0) {
				for (i = row; i > row + 1 - boat.size; i--) {
					if (board[i][col].boat != NULL) {
						return 0;
					}
				}
				return 1;
			}
			return 0;
		case WEST: /* Back of the boat goes to EAST  */	
			if (col + boat.size <= BOARD_SIZE) {
				for (i = col; i < col + boat.size; i++) {
					if (board[row][i].boat != NULL) {
						return 0;
					}
				}
				return 1;
			}
			return 0;
		case NORTH: /* Back of the boat goes to SOUTH  */
			if (row + boat.size <= BOARD_SIZE) {
				for (i = row; i < row + boat.size; i++) {
					if (board[i][col].boat != NULL) {
						return 0;
					}
				}
				return 1;
			}
			return 0;
		case EAST: /* Back of the boat goes to WEST  */
			if (col + 1 - boat.size >= 0) {
				for (i = col; i > col + 1 - boat.size; i--) {
					if (board[row][i].boat != NULL) {
						return 0;
					}
				}
				return 1;
			}
			return 0;
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

int check_shot_possible (Cell board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
	return (board[row][col].touched == 0);
}
