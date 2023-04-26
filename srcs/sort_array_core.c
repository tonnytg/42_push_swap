/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/04/26 00:33:41 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_indice(int total, t_pair *array)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < total)
	{
		if (array[i].index > max)
			max = array[i].index;
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

int get_bit(int value, int bit)
{
	return (value >> bit) & 1;
}

void counting_sort_bit(int total, t_pair *array, int bit)
{
	int i;
	int top_a;
	t_pair *swap;
	t_pair tmp;

	swap = ft_calloc(total, sizeof(t_pair));
	i = 0;
	while (i < total)
	{
		top_a = last_p_array_void(total, array);
//		printf("top_a: %d\n", top_a);
		tmp = array[top_a];
//		printf("value tmp: %ld\n", tmp.value);
//		printf("index tmp: %ld\n", tmp.index);
//		printf("bit divisor: %d\n", bit);
//		printf("bit rest: %d\n", get_bit(tmp.index, bit));
		if (get_bit(tmp.index, bit) == 0)
		{
			sort_p_void(total, array, swap, 'b');
		}
		else
		{
			sort_r_void(total, array, swap, 'a');
		}
//		printf("----------------------\n");
		i++;
	}

	// retorna todos os elementos para a array
	top_a = last_p_array_void(total, swap);
	while (top_a >= 0)
	{
		sort_p_void(total, array, swap, 'a');
		top_a = last_p_array_void(total, swap);
	}
	free(swap);
}

void raddixsort(int total, t_pair *array)
{
	int max;
	int num_bits;
	int i;

	max = get_max_indice(total, array);
	num_bits = get_count_bit(max);
	i = 0;
	while (i < num_bits)
	{
		counting_sort_bit(total, array, i);
		i++;
	}
}

