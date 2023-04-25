#include "../includes/push_swap.h"
#include "../includes/libft.h"
#include <stdio.h>
#include <criterion/criterion.h>

Test(push_swap, check_values) {
	t_pair pair;

	pair.value = 1;
	cr_assert_eq(pair.value, 1);
}
