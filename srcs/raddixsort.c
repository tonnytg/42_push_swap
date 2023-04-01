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

//int	push_swap_needed(int total, void **array)
//{
//	int	i;
//
//	i = 0;
//	while (i < total - 1)
//	{
//		if (array[i] != NULL && array[i + 1] != NULL)
//		{
//			if (*(int *)array[i] < *(int *)array[i + 1])
//				return (1);
//		}
//		i++;
//	}
//	return (0);
//}

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
			return 0; // Retorna 0 (falso) se os elementos não estiverem em ordem crescente
		}
		i++;
	}
	return 1; // Retorna 1 (verdadeiro) se a pilha estiver ordenada
}

int get_bit(int value, int bit)
{
	return (value >> bit) & 1;
}

void counting_sort_bit(int total, void **array, void **swap, int bit)
{
	int i;
	int *value_ptr;
	int top_a;

	i = 0;
	while (i < total)
	{
		top_a = last_p_array_void(total, array);
		value_ptr = array[top_a];
		if (get_bit(value_ptr[1], bit) == 0)
		{
			top_a = last_p_array_void(total, array);
			value_ptr = array[top_a];
			sort_p_void(total, array, swap, 'b');
		}
		else
		{
			rotate_array(total, array, "cw");
			if (push_swap_needed(total, array) == 1)
				break ;
		}
		i++;
	}

	top_a = last_p_array_void(total, swap);
	while (top_a >= 0)
	{
		sort_p_void(total, array, swap, 'a');
		top_a = last_p_array_void(total, swap);
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
	free(swap);
}

//void raddixsort(int total, void **array)
//{
//	void **swap;
//	int max;
//	int num_bits;
//	int i;
//
//	swap = new_array_void(total);
//	max = get_max_indice(total, array);
//	num_bits = get_count_bit(max);
//	i = 0;
//	while (i < num_bits)
//	{
//		counting_sort_bit(total, array, swap, i);
//		i++;
//	}
//	free(swap);
//}
