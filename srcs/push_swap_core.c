/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 13:59:28 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	push_all_values(int total, t_pair *array, char **argv)
{
	int	i;

	i = total;
	while (i >= 1)
	{
		push_void(total, array, ft_atol(argv[i]), 0);
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

void set_index(int total, t_pair *array)
{
	int		i;
	t_pair	*pairs;

	pairs = malloc(total * sizeof(t_pair));
	i = 0;
	while (i < total)
	{
		pairs[i].value = array[i].value;
		pairs[i].index = i;
		i++;
	}
	quicksort(pairs, 0, total - 1);
	i = 0;
	while (i < total)
	{
		array[pairs[i].index].index = i;
		i++;
	}
	free(pairs);
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
		ft_printf("sort 3\n");
		ft_sort_five_elements(total, array);
		return ;
	}
}

void	push_swap(int argc, char **argv)
{
	t_pair	*stack_a;
	int		total;

	total = argc - 1;
	stack_a = ft_calloc(total, sizeof(t_pair));
	push_all_values(total, stack_a, argv);
	set_index(total, stack_a);
	if (sort_is_needed(total, stack_a))
		sort_array(total, stack_a);
	print_array(total, stack_a);
	free(stack_a);
}
