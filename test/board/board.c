#include "minunit.h"
#include "board.h"
#include "boat.h"
#include "config.h"

/* TEST SHOT POSSIBLE  */
MU_TEST (test_shot_not_possible) {
	Cell board[BOARD_SIZE][BOARD_SIZE];
	int res;

	new_board(board);
	
	board[0][0].touched = 1;

	res = check_shot_possible(board, 0, 0);

	mu_assert(res == 0, "The shot is possible");
}

MU_TEST (test_shot_possible) {
	Cell board[BOARD_SIZE][BOARD_SIZE];
	int res;

	new_board(board);

	res = check_shot_possible(board, 5, 5);

	mu_assert(res == 1, "The shot isn't possible");
}

/* TEST BOAT PLACEMENT  */
MU_TEST (test_boat_placement_north) {
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];

	new_board(board);
	boat_factory(&cruiser, CRUISER);

	place_boat(board, &cruiser, 0, 0, NORTH);

	mu_assert(board[0][0].boat != NULL, "The starting position doesn't have the boat");
	mu_assert(board[2][0].boat != NULL, "The end position doesn't have the boat");
	mu_assert(board[3][0].boat == NULL, "The cell 0;5 can't have the boat in it");
}
MU_TEST (test_boat_placement_east) {
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];

	new_board(board);
	boat_factory(&cruiser, CRUISER);

	place_boat(board, &cruiser, 0, 5, EAST);

	mu_assert(board[0][5].boat != NULL, "The starting position doesn't have the boat");
	mu_assert(board[0][3].boat != NULL, "The end position doesn't have the boat");
	mu_assert(board[0][2].boat == NULL, "The cell 0;5 can't have the boat in it");
}
MU_TEST (test_boat_placement_south) {
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];

	new_board(board);
	boat_factory(&cruiser, CRUISER);

	place_boat(board, &cruiser, 5, 0, SOUTH);

	mu_assert(board[5][0].boat != NULL, "The starting position doesn't have the boat");
	mu_assert(board[3][0].boat != NULL, "The end position doesn't have the boat");
	mu_assert(board[1][0].boat == NULL, "The cell 0;5 can't have the boat in it");
}

MU_TEST (test_boat_placement_west) {
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];

	new_board(board);
	boat_factory(&cruiser, CRUISER);

	place_boat(board, &cruiser, 0, 0, WEST);

	mu_assert(board[0][0].boat != NULL, "The starting position doesn't have the boat");
	mu_assert(board[0][2].boat != NULL, "The end position doesn't have the boat");
	mu_assert(board[0][3].boat == NULL, "The cell 0;5 can't have the boat in it");
}

/* TEST BOAT PLACEMENT POSSIBLE  */
MU_TEST (test_boat_position_out_south) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 8, 5, NORTH);

	mu_assert(res == 0, "The boat feets in board");
}

MU_TEST (test_boat_position_in_south) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 5, 5, NORTH);

	mu_assert(res == 1, "The boat doesn't feets in board");
}

MU_TEST (test_boat_position_out_east) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 1, 8, WEST);

	mu_assert(res == 0, "The boat feets in board");
}

MU_TEST (test_boat_position_in_east) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 6, 5, WEST);

	mu_assert(res == 1, "The boat doesn't feets in board");
}

MU_TEST (test_boat_position_out_north) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 1, 8, SOUTH);

	mu_assert(res == 0, "The boat feets in board");
}

MU_TEST (test_boat_position_in_north) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 6, 5, SOUTH);

	mu_assert(res == 1, "The boat doesn't feets in board");
}

MU_TEST (test_boat_position_out_west) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 8, 2, EAST);

	mu_assert(res == 0, "The boat feets in board");
}

MU_TEST (test_boat_position_in_west) {
	int res;
	Boat cruiser;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	
	new_board(board);
	boat_factory(&cruiser, CRUISER);

	res = check_if_boat_feets_in_board(board, cruiser, 6, 5, EAST);

	mu_assert(res == 1, "The boat doesn't feets in board");
}

/* TEST INITIALIZATION  */
MU_TEST (test_new_board) {
	Cell board[BOARD_SIZE][BOARD_SIZE];	

	new_board(board);

	mu_assert(board[0][0].touched == 0, "The touched isn't `0`");
	mu_assert(board[0][0].boat == NULL, "The boat isn't `NULL`");
	mu_assert(board[BOARD_SIZE-1][BOARD_SIZE-1].touched == 0, "The touched isn't `0`");
	mu_assert(board[BOARD_SIZE-1][BOARD_SIZE-1].boat== NULL, "The touched isn't `NULL`");
}

/* TEST_LOGIC  */
MU_TEST_SUITE (test_suite) {
	MU_RUN_TEST(test_new_board);
	MU_RUN_TEST(test_boat_position_out_north);
	MU_RUN_TEST(test_boat_position_in_north);
	MU_RUN_TEST(test_boat_position_out_east);
	MU_RUN_TEST(test_boat_position_in_east);
	MU_RUN_TEST(test_boat_position_out_west);
	MU_RUN_TEST(test_boat_position_in_west);
	MU_RUN_TEST(test_boat_position_out_south);
	MU_RUN_TEST(test_boat_position_in_south);
	MU_RUN_TEST(test_boat_placement_north);
	MU_RUN_TEST(test_boat_placement_east);
	MU_RUN_TEST(test_boat_placement_south);
	MU_RUN_TEST(test_boat_placement_west);
	MU_RUN_TEST(test_shot_not_possible);
	MU_RUN_TEST(test_shot_possible);
}

int main(void) {
	MU_RUN_SUITE(test_suite);	
	MU_REPORT();

	return minunit_status;
}
