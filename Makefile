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
			srcs/stack_array_utils.c \
			srcs/stack_array_core.c \
			srcs/sort_array_utils2.c \
			srcs/sort_array_utils.c \
			srcs/sort_array_core.c \
			srcs/push_swap_utils.c \
			srcs/push_swap_core.c \
			srcs/main.c
OBJS  	= $(FILES:.c=.o)
CC 		= gcc
CC_ARGS = -Wextra -Wall -Werror
LIBS	= libs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_ARGS) $(OBJS) -L $(LIBS) -lft -o $(NAME)
	ar rsc $(LIBS)/lib$(NAME).a $(OBJS)

%.o: %.c
	mkdir -p libs
	make -C libft
	cp -a libft/libft.h ./includes/
	cp -a libft/libft.a ./libs/
	gcc $(CC_ARGS) -c $< -o $@

test: all
	@make -C tests

debug:
	$(CC) $(CC_ARGS) -g $(FILES) -L $(LIBS) -lft -o srcs/$(NAME)

clean:
	make -C libft clean
	rm $(OBJS)

fclean: clean
	make -C libft fclean
	rm push_swap
	rm $(LIBS)/libft.*

re: fclean all

.PHONY:            all clean fclean re 
