/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/22 02:34:44 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	int *array;
	int total;
	int	i;

	total = argc - 1;
	i = 1;
	array = new_array(total);
	while (i <= total)
	{
		push(array, argv[i][0]);
		i++;
	}
	ft_sort(total, array);

	// Define um array de void
	void **array1;
	array1 = new_array_void(total);
	// Imprime um array de void
	print_array_void(total, array1);
	i = 1;
	while (i <= total)
	{
		// define cada valor em um void
		push_void(argc, array, argv[i][0]);
		i++;
	}	
	ft_sort_void(total, array1);
}
