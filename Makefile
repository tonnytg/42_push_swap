NAME   	= push_swap
HEADER 	= $(NAME).h
FILES 	= srcs/push_swap.c srcs/utils_array.c
OBJS  	= $(FILES:.c=.o)
CC 		= gcc
CC_ARGS = -g1 -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_ARGS) $(OBJS) -o $(NAME)

%.o: %.c
	gcc -c $< -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm push_swap

re: fclean all

.PHONY:            all clean fclean re 