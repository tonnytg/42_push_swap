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

int	sort_s_void(int total, void **array, void **swap, char c)
{
	int	top_a;
	int	top_s;
	int	*value_ptr;

	if (c == 'a')
	{
		top_a = last_p_array_void(total, array);
		value_ptr = array[top_a];
		array[top_a] = array[top_a - 1];
		array[top_a - 1] = value_ptr;
		write(1, "sa", 2);
		return (0);
	}
	if (c == 'b')
	{
		top_s = last_p_array_void(total, swap);
		value_ptr = swap[top_s];
		swap[top_s] = swap[top_s - 1];
		swap[top_s - 1] = value_ptr;
		write(1, "sa", 2);
		return (0);
	}
	if (c == 's')
	{
		write(1, "ss", 2);
		return (0);
	}
	return (1);
}


Test(sort_s_void, passing) {

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

	sort_s_void(3, stack, NULL, 'a');
	free(value_ptr);
	value_ptr = stack[2];
	cr_assert_eq(value_ptr[0], 1);
}
