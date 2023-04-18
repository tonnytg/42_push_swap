#include <criterion/criterion.h>
#include <unistd.h>

int	last_p_array_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i <= total)
	{
		if (array[i] != NULL && array[i] != 0x0 && i != total)
			i++;
		else
			return (i - 1);
	}
	return (-1);
}

void	rotate_array(int total, void **array, char *option)
{
	int		i;
	int		top_a;
	int		*tmp;

	if (strcmp(option, "cw") == 0)
	{
		top_a = last_p_array_void(total, array);
		tmp = array[top_a];
		i = top_a;
		while (i > 0)
		{
			array[i] = array[i - 1];
			i--;
		}
		array[0] = tmp;
		return ;
	}
	if (strcmp(option, "ccw") == 0)
	{
		top_a = last_p_array_void(total, array);
		tmp = array[0];
		i = 0;
		while (i < top_a)
		{
			array[i] = array[i + 1];
			i++;
		}
		array[top_a] = tmp;
		return ;
	}
	exit (1);
}

int	sort_rr_void(int total, void **array, void **swap, char c)
{
	if (c == 'a')
	{
		write(1, "rra", 3);
		rotate_array(total, array, "ccw");
		return (0);
	}
	if (c == 'b')
	{
		write(1, "rrb", 3);
		rotate_array(total, swap, "ccw");
		return (0);
	}
	if (c == 'r')
	{
		write(1, "rrr", 3);
		rotate_array(total, array, "ccw");
		rotate_array(total, swap, "ccw");
		return (0);
	}
	return (1);
}

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.

Test(sort_rr_void, passing) {

	void **stack = malloc(sizeof(void *) * 3);

	int *value_ptr = malloc(sizeof(int) * 2);
	value_ptr[0] = 0;
	value_ptr[1] = 0;

	int *value_ptr1 = malloc(sizeof(int) * 2);
	value_ptr1[0] = 1;
	value_ptr1[1] = 1;

	int *value_ptr2 = malloc(sizeof(int) * 2);
	value_ptr2[0] = 2;
	value_ptr2[1] = 2;

	stack[0] = value_ptr;
	stack[1] = value_ptr1;
	stack[2] = value_ptr2;

	sort_rr_void(3, stack, NULL, 'a');

	cr_assert_eq(*(int *)stack[0], 1);
	cr_assert_eq(*(int *)stack[1], 2);
	cr_assert_eq(*(int *)stack[2], 0);
}
