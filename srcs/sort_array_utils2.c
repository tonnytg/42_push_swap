/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:07:26 by antthoma          #+#    #+#             */
/*   Updated: 2023/04/26 00:20:36 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_array(int total, t_pair *array, char *option)
{
	int		i;
	int		top;
	t_pair	tmp;

	if (ft_strcmp(option, "cw") == 0)
	{
		top = last_p_array_void(total, array);
		tmp.value = array[top].value;
		tmp.index = array[top].index;
		i = top;
		while (i > 0)
		{
			array[i].value = array[i - 1].value;
			array[i].index = array[i - 1].index;
			i--;
		}
		array[0].value = tmp.value;
		array[0].index = tmp.index;
		return ;
	}
	if (ft_strcmp(option, "ccw") == 0)
	{
		top = last_p_array_void(total, array);
		tmp.value = array[0].value;
		tmp.index = array[0].index;
		i = 0;
		while (i < top)
		{
			array[i].value = array[i + 1].value;
			array[i].index = array[i + 1].index;
			i++;
		}
		array[top].value = tmp.value;
		array[top].index = tmp.index;
		return ;
	}
	exit (1);
}
