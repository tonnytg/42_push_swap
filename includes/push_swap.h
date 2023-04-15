/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:57:07 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 05:34:56 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct s_pair
{
	long int	value;
	long int	indice;
}	t_pair;

int		check_values(int total, char **values);
void	push_swap(int argc, char **argv);
int		push_swap_needed(int total, void **array);
void	*new_array_void(int total);
void	set_clean_void(int total, void **array);
void	print_array_void(int total, void **array, void **swap);
int		last_p_array_void(int total, void **array);
void    rotate_array(int total, void **array, char *option);
void	set_erease_void(int total, void **array);
void	push_all_values(int total, void **array, char **argv);
void	push_void(int total, void **array, int value, int indice);
int		*pop_void(int total, void **array);
void	ft_sort(int total, int *array);
void	ft_sort_void(int total, void **array);
int		sort_s_void(int total, void **array, void **swap, char c);
int		sort_r_void(int total, void **array, void **swap, char c);
int		sort_rr_void(int total, void **array, void **swap, char c);
int		sort_p_void(int total, void **array, void **swap, char c);
void	raddixsort(int total, void **array);
void	reset_array_indice(int total, void **array);
void	set_array_indice(int size, void **array);
void	print_indices(int total, void **array);
int		get_max_indice(int total, void **array);
#endif
