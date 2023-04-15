#include <CUnit/Basic.h>
#include "push_swap.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define NAME "Function Check Value"
// Must be return 0 has only numbers
// Must be return 1 has a letter or diferent of numbers

int valid_check_values(char *args)
{
	int argc = 3;
	char *argv[] = {"./push_swap", args, "2", "3"};
	return check_values(argc, argv);
}

void test(void) {
	CU_ASSERT_EQUAL(valid_check_values("3"), 0);
	CU_ASSERT_EQUAL(valid_check_values("a"), 1)
}

int main() {
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite(NAME, NULL, NULL);
	CU_add_test(suite, NAME, test);
	CU_basic_set_mode(CU_BRM_VERBOSE);

	CU_basic_run_tests();

	CU_basic_show_failures(CU_get_failure_list());
	printf("\n");

	unsigned int num_failures = CU_get_number_of_failures();
	if (num_failures == 0) {
		printf(ANSI_COLOR_GREEN "All tests passed\n" ANSI_COLOR_RESET);
	} else {
		printf(ANSI_COLOR_RED "%d test(s) failed\n" ANSI_COLOR_RESET, num_failures);
	}

	CU_cleanup_registry();

	return num_failures;
}