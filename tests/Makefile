LIBS	= ../libs
SRCS	= ../srcs

all: tests

tests:
	@gcc -o check_values_test check_values_test.c $(SRCS)/check_values.c -L $(LIBS) -lft -lcriterion
	./check_values_test
	@gcc -o array_utils_test array_utils_test.c $(SRCS)/array_utils.c -L $(LIBS) -lft -lcriterion
	./array_utils_test

clean:
	rm -f check_values_test

fclean: clean

re: fclean all

.PHONY:            all clean fclean re