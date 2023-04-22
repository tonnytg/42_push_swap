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

void	push_swap(int argc, char **argv)
{
	t_pair	*stack_a;
	int		total;

	total = argc - 1;
	stack_a = ft_calloc(total, sizeof(t_pair));
	push_all_values(total, stack_a, argv);
	print_array(total, stack_a);
	free(stack_a);
}
