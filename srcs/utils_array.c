/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:29:36 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/20 08:30:10 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_clean(int *array, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		array[i] = -1;
		i++;
	}
}

int	*new_array(int total)
{
	int	*array;

	array = malloc(sizeof(int) * total);
	set_clean(array, total);
	return (array);
}

void	print_array(int *array, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		ft_printf("[%d] - %d\n", i, array[i]);
		i++;
	}
}
