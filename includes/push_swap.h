/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:57:07 by antthoma          #+#    #+#             */
/*   Updated: 2023/04/26 00:19:31 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct s_pair
{
	long int	value;
	long int	index;
	int 		is_active;
}	t_pair;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

int		check_values(int total, char **values);
int		sort_is_needed(int total, t_pair *array);
void	push_swap(int argc, char **argv);
void	*new_array_void(int total);
void	set_clean_void(int total, t_pair *array);
void	print_array_void(int total, t_pair *array, t_pair *swap);
int		last_p_array_void(int total, t_pair *array);
void	rotate_array(int total, t_pair *array, char *option);
void	set_erease_void(int total, void **array);
void	push_all_values(int total, t_pair *array, char **argv);
int		push(int total, t_pair *array, long int value, int index);
t_pair	pop(int total, t_pair *array);
void	ft_sort_void(int total, t_pair *array);
int		sort_s_void(int total, t_pair *array, t_pair *swap, char c);
int		sort_r_void(int total, t_pair *array, t_pair *swap, char c);
int		sort_rr_void(int total, t_pair *array, t_pair *swap, char c);
int		sort_p_void(int total, t_pair *array, t_pair *swap, char c);
void	raddixsort(int total, t_pair *array);
//void	reset_array_indice(int total, t_pair *array);
//void	set_array_indice(int size, t_pair *array);
void	print_indices(int total, t_pair *array);
int		get_max_indice(int total, t_pair *array);
int		is_duplicated(int total, t_pair *array);
void	print_array(int total, t_pair *array);
void	ft_sort_three_elements(int total, t_pair *array);
void	ft_sort_four_elements(int total, t_pair *array);
void	ft_sort_five_elements(int total, t_pair *array);
long int find_min(int total, t_pair *array);
long int	find_min(int total, t_pair *array);
void	move_stack(int total, t_pair *array, t_pair *swap, int n_e);

#endif
