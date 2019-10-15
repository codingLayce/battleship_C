#include "../../src/boat/boat.h"
#include "../../include/minunit.h"

MU_TEST(test_carrier) {

}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_carrier);
}

int main(void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();

	return minunit_status;
}
