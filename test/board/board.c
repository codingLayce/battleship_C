#include "minunit.h"
#include "board.h"
#include "config.h"

MU_TEST (test_new_board) {
	Cell board[BOARD_SIZE][BOARD_SIZE];	

	new_board(board);

	mu_assert(board[0][0].touched == 0, "The touched isn't `0`");
	mu_assert(board[0][0].boat == NULL, "The boat isn't `NULL`");
	mu_assert(board[BOARD_SIZE-1][BOARD_SIZE-1].touched == 0, "The touched isn't `0`");
	mu_assert(board[BOARD_SIZE-1][BOARD_SIZE-1].boat== NULL, "The touched isn't `NULL`");
}

MU_TEST_SUITE (test_suite) {
	MU_RUN_TEST(test_new_board);
}

int main(void) {
	MU_RUN_SUITE(test_suite);	
	MU_REPORT();

	return minunit_status;
}
