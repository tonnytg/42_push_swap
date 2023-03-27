/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddixsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 13:59:28 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raddixsort(int total, void **array)
{
	void	**swap;
	int i;
	int *value_ptr;
	int *value_ptr2;
	char *mask;

	swap = new_array_void(total);

	// create raddixsort to sort array of void using the indice of vector, each indice need to convert to bit
	// this can be done using a mask, and then shift the mask to the right
	// the mask will be 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
	i = 0;
	while (i < total)
	{
		value_ptr = array[i];
		ft_printf("value_ptr: %d", *value_ptr);
		// char    *ft_char_to_bit(int dec)
		mask = ft_char_to_bit(value_ptr[1]);
		value_ptr = (int *)array[i];
		if (value_ptr[1] == 0)
			push_void(total, swap, array[i]);
		else
			push_void(total, array, array[i]);
		i++;
	}


	print_indices(total, array);
	free(swap);
}
