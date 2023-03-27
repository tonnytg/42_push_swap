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

int	get_max_indice(int total, void **array)
{
	int	i;
	int	max;
	int *value_ptr;

	i = 0;
	max = 0;
	while (i < total)
	{
		value_ptr = array[i];
		if (value_ptr[1] > max)
			max = value_ptr[1];
		i++;
	}
	return (max);
}

int	get_count_bit(int value)
{
	int	i;
	int count;
	char *temp;

	i = 8;
	count = 0;
	temp = ft_char_to_bit(value);
	while (i > 0)
	{
		if (temp[i] == '1')
			count = i;
		i--;
	}
	count = 8 - count;
	return (count);
}

void	raddixsort(int total, void **array)
{
	void	**swap;
	int i;
	int *value_ptr;
	int max;
	int counter;

	swap = new_array_void(total);

	max = get_max_indice(total, array);
	counter = 0;
	counter = get_count_bit(max);
	ft_printf("counter: %d - max: %d\n", counter, max);

	i = 0;
	while (i < total)
	{
		value_ptr = array[i];
		ft_printf("%s\n", ft_char_to_bit(value_ptr[1]));
		i++;
	}

	print_indices(total, array);
	free(swap);
}
