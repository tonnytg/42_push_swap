/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:20:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 13:59:37 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_duplicates(int total, void **array)
{
	int i, j;

	i = 0;
	while (i < total)
	{
		j = i + 1;
		while (j < total)
		{
			if (*(int *)array[i] == *(int *)array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int push_swap_needed(int total, void **array)
{
	int i;

	i = 0;
	while (i < total - 1)
	{
		if (array[i] != NULL && array[i + 1] != NULL)
		{
			if (*(int *)array[i] < *(int *)array[i + 1])
				return (1);
		}
		i++;
	}
	return (0);
}

// TODO: Escrever teste unitário para validar
void	push_void(int total, void **array, int value, int indice)
{
	int	*value_ptr;
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	if (i == total)
	{
		ft_printf("Panic, array it is full");
		exit (1);
	}
	value_ptr = malloc(sizeof(int) * 2);
	value_ptr[0] = value;
	value_ptr[1] = indice;
	array[i] = value_ptr;
}

// TODO: Escrever teste unitário para validar
int	*pop_void(int total, void **array)
{
	int	i;
	int *value_ptr;

	i = 0;
	while (array[i] != NULL && i < total)
	{
		i++;
	}
	value_ptr = array[i - 1];
	array[i - 1] = NULL;
	return (value_ptr);
}

// TODO: Escrever teste unitário para validar
int	peek_void(int total, void **array)
{
	int	i;
	int	top;

	i = 0;
	while (array[i] != NULL && i < total)
	{
		i++;
	}
	top = *(int *)array[i - 1];
	return (top);
}
