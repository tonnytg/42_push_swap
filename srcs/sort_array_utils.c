/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:30:19 by antthoma          #+#    #+#             */
/*   Updated: 2023/03/06 22:39:43 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sort_s_void(int total, t_pair *array, t_pair *swap, char c)
{
	int	top_a;
	int	top_s;
	t_pair tmp;

	if (c == 'a')
	{
		top_a = last_p_array_void(total, array);
		tmp.value = array[top_a].value;
		tmp.index = array[top_a].index;
		array[top_a].value = array[top_a - 1].value;
		array[top_a].index = array[top_a - 1].index;
		array[top_a - 1].value = tmp.value;
		array[top_a - 1].index = tmp.index;
		ft_printf("s%c\n", c);
		return (0);
	}
	if (c == 'b')
	{
		top_s = last_p_array_void(total, swap);
		tmp.value = swap[top_s].value;
		tmp.index = swap[top_s].index;
		swap[top_s].value = swap[top_s - 1].value;
		swap[top_s].index = swap[top_s - 1].index;
		swap[top_s - 1].value = tmp.value;
		swap[top_s - 1].index = tmp.index;
		ft_printf("s%c\n", c);
		return (0);
	}
	if (c == 's')
	{
		ft_printf("s%c\n", c);
		return (0);
	}
	return (1);
}

int	sort_r_void(int total, t_pair *array, t_pair *swap, char c)
{
	if (c == 'a')
	{
		ft_printf("r%c\n", c);
		rotate_array(total, array, "cw");
		return (0);
	}
	if (c == 'b')
	{
		ft_printf("r%c\n", c);
		rotate_array(total, swap, "cw");
		return (0);
	}
	if (c == 'r')
	{
		ft_printf("r%c\n", c);
		rotate_array(total, array, "cw");
		rotate_array(total, swap, "cw");
		return (0);
	}
	return (1);
}

int	sort_rr_void(int total, t_pair *array, t_pair *swap, char c)
{
	if (c == 'a')
	{
		ft_printf("rr%c\n", c);
		rotate_array(total, array, "ccw");
		return (0);
	}
	if (c == 'b')
	{
		ft_printf("rr%c\n", c);
		rotate_array(total, swap, "ccw");
		return (0);
	}
	if (c == 'r')
	{
		ft_printf("rr%c\n", c);
		rotate_array(total, array, "ccw");
		rotate_array(total, swap, "ccw");
		return (0);
	}		
	return (1);
}

int	sort_p_void(int total, t_pair *array, t_pair *swap, char c)
{
	t_pair tmp;

	if (c == 'a')
	{
		tmp = pop(total, swap);
		push(total, array, tmp.value, tmp.index);
	}
	else if (c == 'b')
	{
		tmp = pop(total, array);
		push(total, swap, tmp.value, tmp.index);
	}
	else
		return (1);
	ft_printf("p%c\n", c);
	return (0);
}
