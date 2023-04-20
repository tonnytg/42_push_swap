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
	void	*tmp;

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
	else if (strcmp(option, "ccw") == 0)
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

int	sort_r_void(int total, void **array, void **swap, char c)
{
	if (c == 'a')
	{
		rotate_array(total, array, "cw");
		return (0);
	}
	else if (c == 'b')
	{
		rotate_array(total, swap, "cw");
		return (0);
	}
	else if (c == 'r')
	{
		rotate_array(total, array, "cw");
		rotate_array(total, swap, "cw");
		return (0);
	}
	return (1);
}

// ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.

Test(sort_r_void, passing) {

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

	sort_r_void(3, stack, NULL, 'a');

	free(value_ptr);
	value_ptr = stack[0];
	cr_assert_eq(value_ptr[0], 2);
	free(value_ptr);
	value_ptr = stack[2];
	cr_assert_eq(value_ptr[0], 1);
}
