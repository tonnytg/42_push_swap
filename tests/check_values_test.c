#include <criterion/criterion.h>

extern int	check_values(int argc, char **argv);

Test(check_values, failing)
{
	char *values1[] = {"./push_swap","a", "1", "2"};
	cr_assert_eq(check_values(4, values1), 1);

	char *values2[] = {"./push_swap", "0", "a", "2"};
	cr_assert_eq(check_values(4, values2), 1);

	char *values3[] = {"./push_swap", "0", "1", "a"};
	cr_assert_eq(check_values(4, values3), 1);
}

Test(check_values, passing)
{
	char *values4[] = {"./push_swap", "0", "1", "2"};
	cr_assert_eq(check_values(4, values4), 0);
}


