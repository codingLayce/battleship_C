#ifndef BOARD_H_GUARD
#define BOARD_H_GUARD

#include "config.h"
#include "cell.h"
#include "boat.h"

/* Fills up the board matrix with default cells.
 * @param board matrix to initiate 
 */
void new_board (Cell board[BOARD_SIZE][BOARD_SIZE]);

/* Checks if the boat feets into the maze depending of his position and direction
 * @param board matrix representing the board
 * @param boat to check
 * @param row startting position
 * @param col starting position
 * @param direction where goes the boat
 * @return 1 if the boat feets, 0 otherwise
 */
int check_if_boat_feets_in_board (Cell board[BOARD_SIZE][BOARD_SIZE], Boat boat, int row, int col, Direction direction); 

/* Places the boat at the gieven position with the given direction.
 * @param board matrix to update
 * @param boat to place
 * @param row starting row position
 * @param col starting col position
 * @param direction where the boat is looking
 */
void place_boat (Cell board[BOARD_SIZE][BOARD_SIZE], Boat *boat, int row, int col, Direction direction);

/* Checks if the shot is possible or not.
 * A shot is possible if the target cell hasn't been shoted yet.
 * @param board matrix to check
 * @param row position of the target cell
 * @param col position of the target cell
 * @return 1 if the shot is possible, 0 otherwise
 */
int check_shot_possible (Cell board[BOARD_SIZE][BOARD_SIZE], int row, int col);

void board_clone(Cell board_clonde[BOARD_SIZE][BOARD_SIZE], Cell board[BOARD_SIZE][BOARD_SIZE]);

#endif
