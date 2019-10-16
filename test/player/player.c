#include <stdlib.h>
#include "minunit.h"
#include "board.h"
#include "boat.h"
#include "player.h"

MU_TEST (test_destroy_player_boat) {
	Player player;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	Boat boat;

	new_board(board);
	boat_factory(&boat, CRUISER);
	player_factory(&player, HUMAN);

	place_boat(board, &boat, 5, 5, NORTH);

	player.boats_alive++;

	boat.hits = 2;

	hit(&board[5][5], &player);

	mu_assert(board[5][5].touched == 1, "The cell isn't touched");
	mu_assert(boat.hits == 3, "The boat isn't touched");
	mu_assert(player.boats_alive == 0, "The player's boat isn't destroyed");
}

MU_TEST (test_hit_player_boat) {
	Player player;
	Cell board[BOARD_SIZE][BOARD_SIZE];
	Boat boat;

	new_board(board);
	boat_factory(&boat, CRUISER);
	player_factory(&player, HUMAN);

	place_boat(board, &boat, 5, 5, NORTH);

	hit(&board[5][5], &player);

	mu_assert(board[5][5].touched == 1, "The cell isn't touched");
	mu_assert(boat.hits == 1, "The boat isn't touched");
}

MU_TEST (test_ia_factory) {
	Player ia;

	player_factory(&ia, IA);

	mu_assert(ia.boats_alive == 0, "The boats_alive isn't `0`");
	mu_assert(ia.play == NULL, "The play function isn't `NUKK`");
}

MU_TEST (test_player_factory) {
	Player player;

	player_factory(&player, HUMAN);

	mu_assert(player.boats_alive == 0, "The boats_alive isn't `0`");
	mu_assert(player.play == NULL, "The play function isn't `NUKK`");	
}

MU_TEST_SUITE (test_suite) {
	MU_RUN_TEST(test_ia_factory);
	MU_RUN_TEST(test_player_factory);
	MU_RUN_TEST(test_hit_player_boat);
	MU_RUN_TEST(test_destroy_player_boat);
}

int main (void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();

	return minunit_status;
}
