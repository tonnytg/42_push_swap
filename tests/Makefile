LIBS	= ../libs
SRCS	= ../srcs

all: tests

lib:
	gcc -o push_swap_test core_test.c -L ../libs -lft -L ../libs -lpush_swap -lcriterion

tests:
	@gcc -o push_swap_utils_test push_swap_utils_test.c $(SRCS)/push_swap_utils.c -L $(LIBS) -lft -lcriterion
	@./push_swap_utils_test
	@gcc -o stack_array_utils_test stack_array_utils_test.c $(SRCS)/stack_array_utils.c -L $(LIBS) -lft -lcriterion
	@./stack_array_utils_test
	@gcc -o stack_array_core_test stack_array_core_test.c $(SRCS)/stack_array_core.c -L $(LIBS) -lft -lcriterion
	@./stack_array_core_test
	@gcc -o sort_utils_test sort_array_utils_test.c -L $(LIBS) -lft -lcriterion
	@./sort_utils_test
	@gcc -o sort_utils_test1 sort_array_utils_test1.c -L $(LIBS) -lft -lcriterion
	@./sort_utils_test1
	@gcc -o sort_utils_test2 sort_array_utils_test2.c -L $(LIBS) -lft -lcriterion
	@./sort_utils_test2

clean:
	rm push_swap_utils_test
	rm stack_array_utils_test
	rm stack_array_core_test
	rm sort_utils_test
	rm sort_utils_test1
	rm sort_utils_test2

re: clean all

.PHONY:            all clean fclean re