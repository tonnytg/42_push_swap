LIBS	= ../libs
SRCS	= ../srcs

all: tests

lib:
	gcc -o push_swap_test core_test.c -L ../libs -lft -L ../libs -lpush_swap -lcriterion

tests:
	@gcc -o core_test core_test.c -L $(LIBS) -lft -lcriterion
	@./core_test

clean:
	rm core_test

re: clean all

.PHONY:            all clean fclean re