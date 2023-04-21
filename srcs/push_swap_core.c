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

void	push_all_values(int total, void **array, char **argv)
{
	int	i;

	i = total;
	while (i >= 1)
	{
		// TODO: Criar uma ft_atol
		// TODO: Subistituir o atoi pra atol
		push_void(total, array, ft_atol(argv[i]), 0);
		i--;
	}
}

void	set_erease_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		array[i] = NULL;
		i++;
	}
}

void	push_swap(int argc, char **argv)
{
	void	**stack_a;
	int		total;

	total = argc - 1;
	stack_a = new_array_void(total);
	push_all_values(total, stack_a, argv);
	reset_array_indice(total, stack_a);
	set_array_indice(total, stack_a);
	int i = 0;
	printf("---stack-start--\n");
	while (i < total)
	{
		long int *value_ptr = stack_a[i];
		printf("[%d]: %ld - indice:%ld\n", i, value_ptr[0], value_ptr[1]);
		i++;
	}
	printf("---stack-end--\n");
	if (push_swap_needed(total, stack_a))
	{
		ft_sort_void(total, stack_a);
		int i = 0;
		while (i < total)
		{
			long int *value_ptr = stack_a[i];
			printf("[%d]: %ld - indice:%ld\n", i, value_ptr[0], value_ptr[1]);
			i++;
		}
	}
	set_erease_void(total, stack_a);
	free(stack_a);
}
