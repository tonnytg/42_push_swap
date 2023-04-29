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

long int	find_min(int total, t_pair *array)
{
	int	i;
	int	min;

	i = 0;
	min = MAX_INT;
	while (i < total)
	{
		if (array[i].is_active != 0)
		{
			if (array[i].index < min)
				min = array[i].index;
		}
		i++;
	}
	return (min);
}

void	decide_side_rotate(int total, t_pair *array, char c, int *side)
{
	int	top;

	top = last_p_array_void(total, array);
	if (*side == -1)
	{
		if (array[top].index > array[top -1].index)
		{
			if (array[top - 1].index > array[0].index)
				*side = 1;
			else
				*side = 0;
		}
	}
	if (*side == 1)
		sort_rr_void(total, array, NULL, c);
	else
		sort_r_void(total, array, NULL, c);
}

void	move_stack(int total, t_pair *array, t_pair *swap, int n_e)
{
	int	top;
	int	min;
	int	side;
	int	trigger;

	side = -1;
	trigger = 0;
	while (trigger < n_e)
	{
		top = last_p_array_void(total, array);
		min = find_min(total, array);
		if (array[top].index == min)
		{
			sort_p_void(total, array, swap, 'b');
			trigger++;
		}
		else
			decide_side_rotate(total, array, 'a', &side);
	}
}

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
