#include <criterion/criterion.h>
#include "../includes/push_swap.h"

Test(push_swap, push_swap_needed)
{
	char *values[] = {"1", "2", "3"};
	cr_assert_eq(check_values(3, values), 0);
}