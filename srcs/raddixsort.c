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

//void	raddixsort(int total, void **array)
//{
//	void	**swap;
//	int i;
//	int *value_ptr;
//	int max;
//	int counter;
//
//	swap = new_array_void(total);
//
//	max = get_max_indice(total, array);
//	counter = 0;
//	counter = get_count_bit(max);
//	ft_printf("counter: %d - max: %d\n", counter, max);
//
//	// create count sort with bit
//	// TODO: create a function to use Counting Sort to organize bits
//
//
//	print_indices(total, array);
//	free(swap);
//}

int get_bit(int value, int bit)
{
	return (value >> bit) & 1;
}

void counting_sort_bit(int total, void **array, void **swap, int bit)
{
	int i;
	int *value_ptr;
	char *bits;
	int top_a;

	i = 0;
	print_indices(total, array);
	ft_printf("[Start]\n");
	while (i < total)
	{
		top_a = last_p_array_void(total, array);
		value_ptr = array[top_a];
		bits = ft_char_to_bit(value_ptr[1]);
		ft_printf("Number: %d - Bits: %s - Bit:%d - GetBit: %d\n", value_ptr[0], bits, bit, get_bit(value_ptr[1], bit));
		if (get_bit(value_ptr[1], bit) == 0)
		{
			top_a = last_p_array_void(total, array);
			value_ptr = array[top_a];
			ft_printf("[1] - top_a:%d - Value: %d - Indice: %d - ", top_a, value_ptr[0], value_ptr[1]);
			ft_printf("[Troca - pb]\n---\n");
			sort_p_void(total, array, swap, 'b');
		}
		else
		{
			ft_printf("[2] - top_a:%d - Value: %d - Indice: %d - ", top_a, value_ptr[0], value_ptr[1]);
			ft_printf("[Rotaciona - ra]\n");
			rotate_array(total, array, "ccw");
			print_indices(total, array);
			ft_printf("---\n");
		}
		i++;
	}

	i = 0;
	while (i < total)
	{
		if (swap[i] != NULL)
		{
			value_ptr = swap[i];
			sort_p_void(total, array, swap, 'a');
		}
		i++;
	}
}

void raddixsort(int total, void **array)
{
	void **swap;
	int max;
	int num_bits;
	int i;

	swap = new_array_void(total);
	max = get_max_indice(total, array);
	num_bits = get_count_bit(max);
	i = 0;
	while (i < num_bits)
	{
		counting_sort_bit(total, array, swap, i);
		i++;
	}
	print_indices(total, array);
	free(swap);
}
