#include <criterion/criterion.h>

extern void *new_array_void(int total);

Test(new_array_void, passing) {
	void **array;
	int **value_ptr;
	int	i = 0;
	int value = 0;
	int index = 0;

	array = new_array_void(3);
	value_ptr = malloc(sizeof(int) * 3);
	while (array[i] != NULL)
		i++;
	i = 0;
	while (i < 3)
	{
		value_ptr[i] = malloc(sizeof(int) * 2);
		value_ptr[i][0] = value;
		value_ptr[i][1] = index;
		i++;
	}
	array[0] = value_ptr[0];
	array[1] = value_ptr[1];

	cr_assert_eq(array[0], value_ptr[0]);
	cr_assert_eq(array[1], value_ptr[1]);
	free(array);
}