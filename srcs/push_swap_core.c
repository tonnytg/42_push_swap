/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/04/26 00:17:13 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_all_values(int total, t_pair *array, char **argv)
{
	int	i;

	i = total;
	while (i >= 1)
	{
		push(total, array, ft_atol(argv[i]), 0);
		i--;
	}
}

void print_array(int total, t_pair *array)
{
	int i = 0;

	while (i < total)
	{
		printf("[%d]: %ld - indice:%ld\n", i, array[i].value, array[i].index);
		i++;
	}
}

void set_my_indice(int total, t_pair *array)
{
	int i;
	int j;
	int max;
	int counter;

	j = 0;
	counter = total;
	while (j < total)
	{
		max = MIN_INT;
		i = 0;
		while (i < total) {
			if (array[i].index == 0 && array[i].value > max) {
				max = array[i].value;
			}
			i++;
		}
		i = 0;
		while (i < total) {
			if (max == array[i].value) {
				array[i].index = counter;
				counter--;
				break;
			}
			i++;
		}
		j++;
	}
}

void sort_array(int total, t_pair *array)
{
	if (total == 2)
	{
		sort_s_void(total, array, NULL, 'a');
		return ;
	}
	if (total == 3)
	{
		ft_sort_three_elements(total, array);
		return ;
	}
	if (total == 4)
	{
		ft_sort_four_elements(total, array);
		return ;
	}
	if (total == 5)
	{
		ft_sort_five_elements(total, array);
		return ;
	}
	raddixsort(total, array);
}

void	push_swap(int argc, char **argv)
{
	t_pair	*stack_a;
	int		total;

	total = argc - 1;
	stack_a = ft_calloc(total, sizeof(t_pair));
	push_all_values(total, stack_a, argv);
	set_my_indice(total, stack_a);
	if (sort_is_needed(total, stack_a))
		sort_array(total, stack_a);
	free(stack_a);
}
