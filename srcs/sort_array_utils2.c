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
	t_pair	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	partition(t_pair *array, long int left, long int right)
{
	long int	pivot;
	long int	i;
	long int	j;

	pivot = array[right].value;
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (array[j].value < pivot)
		{
			i++;
			change(&array[i], &array[j]);
		}
		j++;
	}
	change(&array[i + 1], &array[right]);
	return (i + 1);
}

void	quicksort(t_pair *array, long int left, long int right)
{
	long int	pivot;

	if (left < right)
	{
		pivot = partition(array, left, right);
		quicksort(array, left, pivot - 1);
		quicksort(array, pivot + 1, right);
	}
}

void	rotate_array(int total, t_pair *array, char *option)
{
	int		i;
	int		top_a;
	t_pair	tmp;

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
//
//void	set_array_indice(int size, t_pair *array)
//{
//	int		i;
//	long int		*vector;
//	t_pair tmp;
//	t_pair	*pairs;
//
//	vector = NULL;
//	pairs = malloc(size * sizeof(t_pair));
//	i = 0;
//	while (i < size)
//	{
//		vector = array[i];
//		pairs[i].value = vector[0];
//		pairs[i].index = i;
//		i++;
//	}
//	quicksort(pairs, 0, size - 1);
//	i = 0;
//
//	while (i < size)
//	{
//		vector = array[pairs[i].index];
//		vector[1] = i;
//		i++;
//	}
//	free(pairs);
//}
