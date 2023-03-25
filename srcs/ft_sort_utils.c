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

#include "push_swap.h"

int	sort_s_void(int total, void **array, void **swap, char c)
{
	int	top_a;
	int	top_s;
	int	*value_ptr;

	if (c == 'a')
	{
		top_a = last_p_array_void(total, array);
		value_ptr = array[top_a];
		array[top_a] = array[top_a - 1];
		array[top_a - 1] = value_ptr;
		ft_printf("s%c\n", c);
		return (0);
	}
	if (c == 'b')
	{
		top_s = last_p_array_void(total, swap);
		value_ptr = swap[top_s];
		swap[top_s] = swap[top_s - 1];
		swap[top_s - 1] = value_ptr;
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

int	sort_r_void(int total, void **array, void **swap, char c)
{
	if (c == 'a')
	{
		ft_printf("r%c\n", c);
		rotate_array(total, array, "ccw");
		return (0);
	}
	if (c == 'b')
	{
		ft_printf("r%c\n", c);
		rotate_array(total, swap, "ccw");
		return (0);
	}
	if (c == 'r')
	{
		ft_printf("r%c\n", c);
		rotate_array(total, array, "ccw");
		rotate_array(total, swap, "ccw");
		return (0);
	}
	return (1);
}

int	sort_rr_void(int total, void **array, void **swap, char c)
{
	if (c == 'a')
	{
		ft_printf("rr%c\n", c);
		rotate_array(total, array, "cw");
		return (0);
	}
	if (c == 'b')
	{
		ft_printf("rr%c\n", c);
		rotate_array(total, swap, "cw");
		return (0);
	}
	if (c == 'r')
	{
		ft_printf("rr%c\n", c);
		rotate_array(total, array, "cw");
		rotate_array(total, swap, "cw");
		return (0);
	}		
	return (1);
}

int	sort_p_void(int total, void **array, void **swap, char c)
{
	int	value;

	if (c == 'a')
	{
		value = pop_void(total, swap);
		push_void(total, array, value);
	}
	else if (c == 'b')
	{
		value = pop_void(total, array);
		push_void(total, swap, value);
	}
	else
		return (1);
	ft_printf("p%c\n", c);
	return (0);
}
