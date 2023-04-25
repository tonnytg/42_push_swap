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

int	push(int total, t_pair *array, long int value, int index)
{
	int	i;

	i = 0;
	while (array[i].is_active != 0)
	{
		i++;
	}
	if (i == total)
		return (0);
	array[i].value = value;
	array[i].index = index;
	array[i].is_active = 1;
	return (1);
}

t_pair pop(int total, t_pair *array)
{
	int	i;
	t_pair		tmp;

	i = 0;
	while (array[i].is_active != 0 && i < total)
	{
		i++;
	}
	tmp.value = array[i - 1].value;
	tmp.index = array[i - 1].index;
	array[i - 1].is_active = 0;
	return (tmp);
}
