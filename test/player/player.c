#include <stdlib.h>
#include "minunit.h"
#include "player.h"

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
}

int main (void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();

	return minunit_status;
}
