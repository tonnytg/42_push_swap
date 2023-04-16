LIBS	= ../libs
SRCS	= ../srcs

all: tests

tests:
	@gcc -o check_values_test check_values_test.c $(SRCS)/check_values.c -L $(LIBS) -lft -lcriterion
	./check_values_test
	@gcc -o push_swap_needed_test push_swap_needed_test.c $(SRCS)/check_values.c -L $(LIBS) -lft -lcriterion
	./push_swap_needed_test
	@gcc -o array_utils_test array_utils_test.c $(SRCS)/array_utils.c -L $(LIBS) -lft -lcriterion
	./array_utils_test
	@gcc -o stack_utils_test stack_utils_test.c $(SRCS)/stack_utils.c -L $(LIBS) -lft -lcriterion
	./stack_utils_test
	@gcc -o ft_sort_utils_test ft_sort_utils_test.c -L $(LIBS) -lft -lcriterion
	./ft_sort_utils_test
	@gcc -o ft_sort_utils_test1 ft_sort_utils_test1.c -L $(LIBS) -lft -lcriterion
	./ft_sort_utils_test1
	@gcc -o ft_sort_utils_test2 ft_sort_utils_test2.c -L $(LIBS) -lft -lcriterion
	./ft_sort_utils_test2

clean:
	rm check_values_test
	rm push_swap_needed_test
	rm array_utils_test
	rm stack_utils

re: clean all

.PHONY:            all clean fclean re