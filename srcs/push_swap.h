/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:57:07 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/22 15:34:49 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

# include <unistd.h>
# include "libft.h"

int		check_values(int total, char **values);
void	push_swap(int argc, char **argv);
int		*new_array(int total);
void	*new_array_void(int total);
void	set_clean(int total, int *array);
void	print_array(int total, int *array);
void	print_array_void(int total, void **array);
int		last_p_array(int *array);
void	push(int *array, int value);
void	push_void(int total, void **array, int value);
int		pop(int *array);
int		pop_void(int total, void **array);
int		peek(int *array);
void	ft_sort(int total, int *array);
void	ft_sort_void(int total, void **array);
int		sort_s(int *array, int *swap, char c);
int		sort_r(int *array, int *swap, char c);
int		sort_rr(int *array, int *swap, char c);
int		sort_p(int *array, int *swap, char c);
int		sort_p_void(int total, void **array, void **swap, char c);
