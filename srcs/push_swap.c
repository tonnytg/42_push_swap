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

void	push_all_values(int total, void **array, char **argv)
{
	int	i;

	i = total;
	while (i >= 1)
	{
		push_void(total, array, ft_atoi(argv[i]), 0);
		i--;
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
	if (push_swap_needed(total, stack_a))
	{
		ft_sort_void(total, stack_a);
	}
	set_erease_void(total, stack_a);
	free(stack_a);
}
