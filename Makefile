# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 23:33:47 by antthoma          #+#    #+#              #
#    Updated: 2023/02/25 14:05:42 by antthoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   	= push_swap
HEADER 	= $(NAME).h
FILES 	= \
			srcs/check_values.c \
			srcs/array_utils.c \
			srcs/push_swap_utils.c \
			srcs/push_swap.c \
			srcs/ft_sort_utils.c \
			srcs/ft_sort.c \
			srcs/raddixsort.c \
			srcs/main.c
OBJS  	= $(FILES:.c=.o)
CC 		= gcc
CC_ARGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_ARGS) $(OBJS) srcs/libft.a -o $(NAME)

%.o: %.c
	make -C libft
	cp -a libft/libft.h srcs/
	cp -a libft/libft.a srcs/
	gcc $(CC_ARGS) -c $< -o $@

debug:
	$(CC) $(CC_ARGS) -g $(FILES) srcs/libft.a -o srcs/$(NAME)

#Run all files with *_test.c
test:
	mkdir -p tests
	gcc srcs/check_values_test.c srcs/check_values.c srcs/push_swap.h srcs/libft.a -lcunit




clean:
	make -C libft clean
	rm $(OBJS)

fclean: clean
	make -C libft fclean
	rm push_swap
	rm srcs/libft.*

re: fclean all

.PHONY:            all clean fclean re 
