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

int is_sorted(int total, void **array)
{
	int i;

	i = 0;
	while (i < total)
	{
		int32_t *value_ptr1 = array[i];
		int32_t *value_ptr2 = array[i + 1];

		if (value_ptr1[1] > value_ptr2[1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int get_bit(int value, int bit)
{
	return (value >> bit) & 1;
}

//void counting_sort_bit(int total, t_pair *array, t_pair *swap, int bit)
//{
//	int i;
//	t_pair tmp;
//	int top_a;
//
//	i = 0;
//	while (i < total)
//	{
//		top_a = last_p_array_void(total, array);
//		tmp = array[top_a];
//		if (get_bit(tmp.index, bit) == 0)
//		{
//			top_a = last_p_array_void(total, array);
//			tmp = array[top_a];
//			sort_p_void(total, array, swap, 'b');
//		}
//		else
//		{
//			rotate_array(total, array, "ccw");
//			if (push_swap_needed(total, array) == 1)
//				break ;
//		}
//		i++;
//	}
//
//	top_a = last_p_array_void(total, swap);
//	while (top_a >= 0)
//	{
//		sort_p_void(total, array, swap, 'a');
//		top_a = last_p_array_void(total, swap);
//	}
//}

void raddixsort(int total, t_pair *array)
{
	void **swap;
	int max;
	int num_bits;
	int i;

	swap = ft_calloc(total, sizeof(t_pair));
	max = get_max_indice(total, array);
	num_bits = get_count_bit(max);
	i = 0;
	while (i < num_bits)
	{
		// counting_sort_bit(total, array, swap, i);
		ft_printf("counting sort");
		i++;
	}
	free(swap);
}

