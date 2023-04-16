#include <criterion/criterion.h>

extern int	push_swap_needed(int total, void **array);

void	*new_array_void(int total)
{
	void	**array;

	array = malloc(total * sizeof(void *));
	return (array);
}

Test(push_swap_needed, passing1) {

int result, expected;
int total = 3;
void **array;

// Top of the stack is the last element of the array
// Last in first out LIFO
int value_ptr1 = 2;
int value_ptr2 = 1;
int value_ptr3 = 0;

array = new_array_void(3);

array[0] = &value_ptr1;
array[1] = &value_ptr2;
array[2] = &value_ptr3;
// 0 1 2 -> input -> no need sort
// 0 1 2 -> output

cr_assert_eq(*(int *)array[0], 2);
cr_assert_eq(*(int *)array[1], 1);
cr_assert_eq(*(int *)array[2], 0);

result = push_swap_needed(total, array);
expected = 0;
cr_assert_eq(result, expected);
}

Test(push_swap_needed, passing2) {

int result, expected;
int total = 6;
void **array;

// Top of the stack is the last element of the array
// Last in first out LIFO
int value_ptr1 = 6;
int value_ptr2 = 5;
int value_ptr3 = 4;
int value_ptr4 = 3;
int value_ptr5 = 2;
int value_ptr6 = 1;

array = new_array_void(3);

array[0] = &value_ptr1;
array[1] = &value_ptr2;
array[2] = &value_ptr3;
array[3] = &value_ptr4;
array[4] = &value_ptr5;
array[5] = &value_ptr6;
// 0 1 2 -> input -> no need sort
// 0 1 2 -> output

cr_assert_eq(*(int *)array[0], 6);
cr_assert_eq(*(int *)array[1], 5);
cr_assert_eq(*(int *)array[2], 4);
cr_assert_eq(*(int *)array[3], 3);
cr_assert_eq(*(int *)array[4], 2);
cr_assert_eq(*(int *)array[5], 1);

result = push_swap_needed(total, array);
expected = 0;
cr_assert_eq(result, expected);
}

Test(push_swap_needed, failing1) {

int result, expected;
int total = 3;
void **array;
int value_ptr1 = 2;
int value_ptr2 = 1;
int value_ptr3 = 3;

array = new_array_void(3);

array[0] = &value_ptr1;
array[1] = &value_ptr2;
array[2] = &value_ptr3;
// 3 1 2 -> input need sort
// 1 2 3 -> output

cr_assert_eq(*(int *)array[0], 2);
cr_assert_eq(*(int *)array[1], 1);
cr_assert_eq(*(int *)array[2], 3);

result = push_swap_needed(total, array);
expected = 1;
cr_assert_eq(result, expected);
}

Test(push_swap_needed, failing2) {

int result, expected;
int total = 6;
void **array;
int value_ptr1 = 8;
int value_ptr2 = 5;
int value_ptr3 = 6;
int value_ptr4 = 3;
int value_ptr5 = 1;
int value_ptr6 = 2;

array = new_array_void(total);

array[0] = &value_ptr1;
array[1] = &value_ptr2;
array[2] = &value_ptr3;
array[3] = &value_ptr4;
array[4] = &value_ptr5;
array[5] = &value_ptr6;
// 3 1 2 -> input need sort
// 1 2 3 -> output

cr_assert_eq(*(int *)array[0], 8);
cr_assert_eq(*(int *)array[1], 5);
cr_assert_eq(*(int *)array[2], 6);
cr_assert_eq(*(int *)array[3], 3);
cr_assert_eq(*(int *)array[4], 1);
cr_assert_eq(*(int *)array[5], 2);

result = push_swap_needed(total, array);
expected = 1;
cr_assert_eq(result, expected);
}