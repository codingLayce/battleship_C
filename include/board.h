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

#endif
