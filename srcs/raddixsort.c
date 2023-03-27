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
	int count[2] = {0, 0};
	int *value_ptr;
	int index;

	// Contagem dos bits 0 e 1
	i = 0;
	while (i < total)
	{
		value_ptr = array[i];
		count[get_bit(value_ptr[1], bit)]++;
		i++;
	}
	ft_printf("contagem dos bits1:%d\n", count[0]);
	ft_printf("contagem dos bits2:%d\n", count[1]);

	// Acumula os valores na contagem
	count[1] += count[0];

	// Aplica o Counting Sort baseado nos bits
	i = total - 1;
	while ( i >= 0)
	{
		value_ptr = array[i];
		index = get_bit(value_ptr[1], bit);
		count[index]--;
		swap[count[index]] = array[i];
		i--;
	}

	// Copia os elementos do array swap de volta para o array original
	i = 0;
	while (i < total)
	{
		array[i] = swap[i];
		i++;
	}
}

void raddixsort(int total, void **array)
{
	void **swap;
	int max;
	int num_bits;
	int bit;

	swap = new_array_void(total);

	max = get_max_indice(total, array);
	num_bits = get_count_bit(max);

	// Aplica o Counting Sort em cada bit
	bit = 0;
	while (bit < num_bits)
	{
		counting_sort_bit(total, array, swap, bit);
		bit++;
	}

	print_indices(total, array);
	free(swap);
}
