#include "boat.h"
#include "minunit.h"


/* FACTORY TESTS  */
MU_TEST (test_carrier_factory) {
	Boat carrier;
	
	boat_factory(&carrier, CARRIER);

	mu_assert(carrier.boat_char == 'A', "The boat_char isn't `À`");
	mu_assert(carrier.size == 5, "The size isn't `5`");
	mu_assert(carrier.hits == 0, "The hits ins't `0`");
}

MU_TEST (test_battleship_factory) {
	Boat battleship;
	
	boat_factory(&battleship, BATTLESHIP);
	
	mu_assert(battleship.boat_char == 'B', "The boat_char isn't `B`");
	mu_assert(battleship.size == 4, "The size isn't `4`");
	mu_assert(battleship.hits == 0, "The hits ins't `0`");		
}

MU_TEST (test_cruiser_factory) {
	Boat cruiser;
	
	boat_factory(&cruiser, CRUISER);
			
	mu_assert(cruiser.boat_char == 'C', "The boat_char isn't `C`");
	mu_assert(cruiser.size == 3, "The size isn't `3`");
	mu_assert(cruiser.hits == 0, "The hits ins't `0`");
}

MU_TEST (test_submarine_factory) {
	Boat submarine;
	
	boat_factory(&submarine, SUBMARINE);
			
	mu_assert(submarine.boat_char == 'S', "The boat_char isn't `S`");
	mu_assert(submarine.size == 3, "The size isn't `3`");
	mu_assert(submarine.hits == 0, "The hits ins't `0`");
}

MU_TEST (test_destroyer_factory) {
	Boat destroyer;
	
	boat_factory(&destroyer, DESTROYER);
			
	mu_assert(destroyer.boat_char == 'D', "The boat_char isn't `D`");
	mu_assert(destroyer.size == 2, "The size isn't `2`");
	mu_assert(destroyer.hits == 0, "The hits ins't `0`");
}

/* TEST LOGIC  */
MU_TEST_SUITE (test_suite) {
	MU_RUN_TEST(test_carrier_factory);
	MU_RUN_TEST(test_battleship_factory);
	MU_RUN_TEST(test_cruiser_factory);
	MU_RUN_TEST(test_submarine_factory);
	MU_RUN_TEST(test_destroyer_factory);
}

int main (void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();

	return minunit_status;
}
