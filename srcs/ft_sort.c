/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:07:26 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/22 16:00:52 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int total, int *array)
{
	int *swap;

	swap = new_array(total);
	int i;
	i = 0;
	while (i < total / 2)
	{
		sort_p(array, swap, 'b');
		i++;
	}
	ft_printf("\n---Array:\n");
	print_array(total, array);
	ft_printf("\n---Swap:\n");
	print_array(total, swap);
	return;
}

void	ft_sort_void(int total, void **array)
{
	void **swap;

	swap = new_array_void(total);
	int i;
	i = 0;
	ft_printf("dividindo os valores\n");
	while (i < total / 2)
	{
		sort_p_void(total, array, swap, 'b');
		i++;
	}
	ft_printf("\n---Array_void:\n");
	print_array_void(total, array);
	ft_printf("\n---Swap_void:\n");
	print_array_void(total, swap);
	sort_p_void(total, array, swap, 'a');	
	ft_printf("\n---Array_void2:\n");
	print_array_void(total, array);
	ft_printf("\n---Swap_void2:\n");
	print_array_void(total, swap);	
	return;
}
