/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:07:26 by antthoma          #+#    #+#             */
/*   Updated: 2023/03/06 23:05:09 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	change(t_pair *x, t_pair *y)
{
	t_pair	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(t_pair *pairs, long int left, long int right)
{
	long int	pivot;
	long int	i;
	long int	j;

	// TODO: Bug bad access with 2 1 3 elements
	pivot = pairs[right].value;
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (pairs[j].value < pivot)
		{
			i++;
			change(&pairs[i], &pairs[j]);
		}
		j++;
	}
	change(&pairs[i + 1], &pairs[right]);
	return (i + 1);
}

void	quicksort(t_pair *pairs, long int left, long int right)
{
	long int	pivot;


	if (left < right)
	{
		pivot = partition(pairs, left, right);
		quicksort(pairs, left, pivot - 1);
		quicksort(pairs, pivot + 1, right);
	}
}

void ft_sort_three_void(int total, void **array)
{
	long int *value_ptr1;
	long int *value_ptr2;
	long int *value_ptr3;
	int i;

	i = 0;
	while (i < total) {
		value_ptr1 = array[0];
		value_ptr2 = array[1];
		value_ptr3 = array[2];

		if (value_ptr3[1] > value_ptr2[1]) {
			sort_s_void(total, array, NULL, 'a');
		}
		if (value_ptr1[1] < value_ptr3[1]) {
			sort_rr_void(total, array, NULL, 'a');
		}
		i++;
	}
}

void	ft_sort_void(int total, void **array)
{
	if (total == 2)
	{
		sort_s_void(total, array, NULL, 'a');
		return ;
	}
	if (total == 3)
	{
		ft_sort_three_void(total, array);
		return ;
	}
	raddixsort(total, array);
	return ;
}

void	rotate_array(int total, void **array, char *option)
{
	int		i;
	int		top_a;
	long int	*tmp;
	long int *value_ptr1;

	if (ft_strcmp(option, "cw") == 0)
	{
		top_a = last_p_array_void(total, array);
		tmp = array[top_a];
		i = top_a;
		while (i > 0)
		{
			array[i] = array[i - 1];
			i--;
		}
		array[0] = tmp;
		return ;
	}
	if (ft_strcmp(option, "ccw") == 0)
	{
		top_a = last_p_array_void(total, array);
		tmp = array[0];
		i = 0;
		while (i < top_a)
		{
			value_ptr1 = array[i + 1];
			array[i] = value_ptr1;
			i++;
		}
		array[top_a] = tmp;
		return ;
	}
	exit (1);
}

void	set_array_indice(int size, void **array)
{
	int		i;
	long int		*vector;
	t_pair	*pairs;

	vector = NULL;
	pairs = malloc(size * sizeof(t_pair));
	i = 0;
	while (i < size)
	{
		vector = array[i];
		pairs[i].value = vector[0];
		pairs[i].indice = i;
		i++;
	}
	quicksort(pairs, 0, size - 1);
	i = 0;
	while (i < size)
	{
		vector = array[pairs[i].indice];
		vector[1] = i;
		i++;
	}
	free(pairs);
}
