/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:29:36 by antthoma          #+#    #+#             */
/*   Updated: 2023/03/06 22:54:09 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_erease_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		array[i] = NULL;
		i++;
	}
}

void	print_indices(int total, void **array)
{
	int	i;
	int	*value_ptr;

	i = 0;
	while (i < total)
	{
		if (array[i] != NULL) {
			value_ptr = array[i];
			ft_printf("Value: %d \t Indice:%d\n", value_ptr[0], value_ptr[1]);
		}
		i++;
	}
}

void	set_clean_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
}

void	*new_array_void(int total)
{
	void	**array;

	array = malloc(total * sizeof(void *));
	return (array);
}

void	reset_array_indice(int total, void **array)
{
	int	*value_ptr;
	int	i;

	i = 0;
	while (i < total)
	{
		value_ptr = array[i];
		value_ptr[1] = 0;
		i++;
	}
}

void	change(t_pair *x, t_pair *y)
{
	t_pair	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(t_pair *pairs, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

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

void	quicksort(t_pair *pairs, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = partition(pairs, left, right);
		quicksort(pairs, left, pivot - 1);
		quicksort(pairs, pivot + 1, right);
	}
}

void	set_array_indice(int size, void **array)
{
	int		i;
	int		*vector;
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

void	print_array_void(int total, void **array, void **swap)
{
	int	i;

	i = 0;
	ft_printf("I\t|A\t|B\n");
	while (i < total)
	{
		if (array[i] != NULL)
		{
			ft_printf("[%d]\t|%d", i, *(int *)array[i]);
		}
		else
			ft_printf("\t|%p", array[i]);
		if (swap[i] != NULL)
			ft_printf("\t|%d\n", *(int *)swap[i]);
		else
			ft_printf("\t|%p\n", swap[i]);
		i++;
	}
}

int	get_max_int_array(int total, void **array)
{
	int	max;
	int	i;
	int	num;

	max = *(int *)array[0];
	i = 1;
	while (i < total)
	{
		num = *(int *)array[i];
		if (num > max)
		{
			max = num;
		}
		i++;
	}
	return (max);
}

// rotate vai ficar responsavel por girar os valores dentro do array
// é um processo custoso porque precisa jogar o valor em uma variavel temporaria
// e depois realocar ela
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

int	last_p_array_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i <= total)
	{
		if (array[i] != NULL && array[i] != 0x0 && i != total)
			i++;
		else
			return (i - 1);
	}
	return (-1);
}
