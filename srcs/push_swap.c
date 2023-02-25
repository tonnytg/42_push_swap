/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:20:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 02:08:43 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_needed(int total, void **array)
{
	int	i;

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

void push_void(int total, void **array, int value)
{
	int *value_ptr;
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	if (i == total)
	{
		// TODO: Validar se no PDF pode imprimir erro em algum momento
		ft_printf("Panic, array it is full");
		exit (1);
	}
	value_ptr = malloc(sizeof(int));
	*value_ptr = value;
	array[i] = value_ptr;
}

int	pop_void(int total, void **array)
{
	int	i;
	int	top;

	i = 0;
	while (array[i] != NULL && i < total)
	{
		i++;
	}
	top = *(int *)array[i - 1];
	array[i - 1] = NULL;
	return (top);
}

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
