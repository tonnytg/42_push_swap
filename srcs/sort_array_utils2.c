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

long int find_min(int total, void **array)
{
	int i;
	int min;
	long int *value_ptr;

	i = 0;
	min = MAX_INT;
	while (i < total)
	{
		if (array[i] != NULL || array[i] != 0x0)
		{
			value_ptr = array[i];
			if (value_ptr[1] < min)
				min = value_ptr[1];
		}
		i++;
	}
	return (min);
}

void ft_sort_five_void(int total, void **array)
{
	int i, trigger;
	long int min;
	long int *value_ptr;
	void **swap;
	int top_a;

	i = 0;
	min = 0;
	trigger = 0;
	swap = new_array_void(total);
	i = 0;
	while (trigger < 2)
	{
		top_a = last_p_array_void(total, array);
		value_ptr = array[top_a];
		min = find_min(total, array);
		if (value_ptr[1] == min)
		{
			sort_p_void(total, array, swap, 'b');
			trigger++;
		}
		else
		{
			sort_r_void(total, array, swap, 'a');
		}
		i++;
	}
	ft_sort_three_void(total - trigger, array);
	int top_b = last_p_array_void(total, swap);
	if (top_b >= 0)
		sort_p_void(total, array, swap, 'a');
	top_b = last_p_array_void(total, swap);
	if (top_b >= 0)
		sort_p_void(total, array, swap, 'a');
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
	if (total == 5)
	{
		ft_sort_five_void(total, array);
		return ;
	}
	raddixsort(total, array);
	return ;
}

void	rotate_array(int total, void **array, char *option)
{
	int		i;
	int		top_a;
	void	*tmp;

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
			array[i] = array[i + 1];
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
