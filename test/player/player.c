#include "minunit.h"
#include "player.h"

MU_TEST(test_ia) {
	mu_assert(1 == 1, "Yes");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_ia);
}

int main(void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();

	return minunit_status;
}
