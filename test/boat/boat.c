#include "../../src/boat/boat.h"
#include "../../include/minunit.h"


/* FACTORY TESTS  */
MU_TEST (test_carrier_factory) {
	Boat carrier;
	
	boat_facotry(&carrier, CARRIER);

	mu_assert(carrier.boat_char == 'A', "The boat_char isn't `À`");
	mu_assert(carrier.size == 5, "The size isn't `5`");
	mu_assert(carrier.hits == 0, "The hits ins't `0`");
}

MU_TEST (test_battleship_factory) {
	Boat battleship;
	
	boat_factory(&battleship, BATTLESHIP);
	
	mu_assert(carrier.boat_char == 'B', "The boat_char isn't `B`");
	mu_assert(carrier.size == 4, "The size isn't `4`");
	mu_assert(carrier.hits == 0, "The hits ins't `0`");		
}

MU_TEST (test_cruiser_factory) {
	boat cruiser;
	
	boat_factory(&cruiser, CRUISER);
			
	mu_assert(carrier.boat_char == 'C', "The boat_char isn't `C`");
	mu_assert(carrier.size == 3, "The size isn't `3`");
	mu_assert(carrier.hits == 0, "The hits ins't `0`");
}

MU_TEST (test_submarine_factory) {
	boat submarine;
	
	boat_factory(&submarine, SUBMARINE);
			
	mu_assert(carrier.boat_char == 'S', "The boat_char isn't `S`");
	mu_assert(carrier.size == 3, "The size isn't `3`");
	mu_assert(carrier.hits == 0, "The hits ins't `0`");
}

MU_TEST (test_destroyer_factory) {
	boat destroyer;
	
	boat_factory(&destroyer, DESTROYER);
			
	mu_assert(carrier.boat_char == 'D', "The boat_char isn't `D`");
	mu_assert(carrier.size == 2, "The size isn't `2`");
	mu_assert(carrier.hits == 0, "The hits ins't `0`");
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
