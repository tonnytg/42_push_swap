#include <criterion/criterion.h>

extern int	*pop_void(int total, void **array);
extern int	push_void(int total, void **array, int value, int index);
extern int	*peek_void(int total, void **array);

Test(pop_void, passing) {

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

	int *value = pop_void(3, stack);
	cr_assert_eq(value[0], 2);
}

Test(push_void, passing) {

	void **stack = malloc(sizeof(void *) * 4);

	int *value_ptr = malloc(sizeof(int) * 2);
	value_ptr[0] = 0;
	value_ptr[1] = 0;

	int *value_ptr1 = malloc(sizeof(int) * 2);
	value_ptr1[0] = 1;
	value_ptr1[1] = 1;

	stack[0] = value_ptr;
	stack[1] = value_ptr1;

	int result = push_void(3, stack, 2, 2);
	cr_assert_eq(result, 1);

	int *value = pop_void(3, stack);
	cr_assert_eq(value[0], 2);
}

Test(peek_void, passing) {

	void **stack = malloc(sizeof(void *) * 4);
	stack[0] = NULL;
	stack[1] = NULL;
	stack[2] = NULL;
	stack[3] = NULL;

	int *value_ptr = malloc(sizeof(int) * 2);
	value_ptr[0] = 0;
	value_ptr[1] = 0;

	int *value_ptr1 = malloc(sizeof(int) * 2);
	value_ptr1[0] = 1;
	value_ptr1[1] = 1;

	stack[0] = value_ptr;
	stack[1] = value_ptr1;
	push_void(4, stack, 2, 2);

	int *value = peek_void(4, stack);
	printf("value[0] = %d\n", value[0]);
	cr_assert_eq(value[0], 2);
}