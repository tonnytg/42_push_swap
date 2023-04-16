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

#include "../includes/push_swap.h"

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

int	*peek_void(int total, void **array)
{
	int	i;
	int	*value_ptr;

	i = 0;
	while (array[i] != NULL && i < total)
	{
		i++;
	}
	value_ptr = array[i - 1];
	return (value_ptr);
}
