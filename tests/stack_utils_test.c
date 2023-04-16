#include <criterion/criterion.h>

extern int	*pop_void(int total, void **array);

Test(pop_void, passing) {

	void **stack;


	cr_assert_eq(1, 1);
}