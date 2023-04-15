#include <criterion/criterion.h>

extern void *new_array_void(int total);

Test(new_array_void, passing) {
	void **array;
	int value_ptr1 = 0;
	int value_ptr2 = 1;
	int value_ptr3 = 2;

	array = new_array_void(3);

	array[0] = &value_ptr1;
	array[1] = &value_ptr2;
	array[2] = &value_ptr3;

	cr_assert_eq(*(int *)array[0], 0);
	cr_assert_eq(*(int *)array[1], 1);
	cr_assert_eq(*(int *)array[2], 2);

	free(array);
}
