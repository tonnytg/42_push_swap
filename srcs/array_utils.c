/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:29:36 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 05:26:59 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_erease_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		free(array[i]);
		i++;
	}
}

void	set_clean_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		array[i] = NULL;
		i++;
	}
}

void	*new_array_void(int total)
{
	void **array;

	array = malloc(total * sizeof(void *));
	set_clean_void(total, array);
	return (array);	
}

void	print_array_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		ft_printf("[%d] - %p\n", i, &array[i]);
		if (array[i] != NULL)
		{
			ft_printf("[%d] - VP:%p\n", i, array[i]);
			ft_printf("[%d] - VD:%d\n", i, *(int *)array[i]);
		}
		else
			ft_printf("[%d] - %p\n", i, array[i]);
		i++;
	}
}

int	last_p_array_void(int total, void **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL && i < total)
	{
		i++;
	}
	return (i - 1);
}
