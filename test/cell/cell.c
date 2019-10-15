#include "cell.h"
#include "boat.h"
#include "minunit.h"

/* TEST NEW CELL  */
MU_TEST (test_new_empty_cell) {
	Cell cell;

	new_cell(&cell, NULL, 0);
	
	mu_assert(cell.boat == NULL, "The boat isn't NULL");
	mu_assert(cell.touched == 0, "The touched isn't `0`"); 
}

MU_TEST (test_new_touched_cell) {
	Cell cell;

	new_cell(&cell, NULL, 1);

	mu_assert(cell.boat == NULL, "The boat isn't NULL");
	mu_assert(cell.touched == 1, "The touched isn't `1`");
}

MU_TEST (test_new_cell_with_boat) {
	Boat destroyer;
	Cell cell;

	boat_factory(&destroyer, DESTROYER);
	new_cell(&cell, &destroyer, 0);

	mu_assert(cell.boat->boat_char == 'D', "The boat_char of boat isn't `D`");
	mu_assert(cell.touched == 0, "The touched isn't `0`");
}

/* TEST LOGIC  */
MU_TEST_SUITE (test_suite) {
	MU_RUN_TEST(test_new_empty_cell);
	MU_RUN_TEST(test_new_touched_cell);
	MU_RUN_TEST(test_new_cell_with_boat);
}

int main (void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();

	return minunit_status;
}
