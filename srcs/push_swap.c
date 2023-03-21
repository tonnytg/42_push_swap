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

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	void	**stack_a;
	int		i;
	int		total;

	total = argc - 1;
	stack_a = new_array_void(total);
	i = total;
	while (i >= 1)
	{
		push_void(total, stack_a, ft_atoi(argv[i]));
		i--;
	}
	reset_array_indice(total, stack_a);
	// i = 0;
	// while (i < total)
	// {
	// 	int *value_ptr;

	// 	value_ptr = stack_a[i];

	// 	ft_printf("Indice:%d\n", value_ptr[1]);
	// 	i++;
	// }
	set_array_indice(total, stack_a);
	i = 0;
	while (i < total)
	{
		int *value_ptr;

		value_ptr = stack_a[i];

		ft_printf("Indice:%d\n", value_ptr[1]);
		i++;
	}	

	if (push_swap_needed(total, stack_a))
	{
		ft_sort_void(total, stack_a);	
	}
	set_erease_void(total, stack_a);
	free(stack_a);
}
