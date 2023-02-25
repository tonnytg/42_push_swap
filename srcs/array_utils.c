/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:29:36 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 02:23:27 by antthoma         ###   ########.fr       */
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
			printf("[%d] - VP:%p\n", i, array[i]);
			printf("[%d] - VD:%d\n", i, *(int *)array[i]);
		}
		else
			printf("[%d] - %p\n", i, array[i]);
		i++;
	}
}

int	last_p_array(int *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0' && array[i] != -1)
	{
		i++;
	}
	ft_printf("return: %d\n", i);
	return (i - 1);
}
