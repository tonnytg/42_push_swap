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

// sort_s muda a posicão do array[top] com a posição[top - 1]
// somente entre eles
// sa sb ss
int	sort_s_void(int total, void **array, void **swap, char c)
{
	int	top_a;
	int	top_s;
	int *value_ptr;

	if (c == 'a')
	{
		// TODO: Executa SA
		top_a = last_p_array_void(total, array);
		value_ptr = array[top_a];
		array[top_a] = array[top_a - 1];
		array[top_a - 1] = value_ptr;
		ft_printf("s%c\n", c);
		return (0);		
	}
	if (c == 'b')
	{
		// TODO: Executa SB
		top_s = last_p_array_void(total, swap);
		value_ptr = swap[top_s];
		swap[top_s] = swap[top_s - 1];
		swap[top_s - 1] = value_ptr;
		ft_printf("s%c\n", c);
		return (0);		
	}
	if (c == 's')
	{
		// TODO: Executa SS
		ft_printf("s%c\n", c);
		return (0);		
	}		
	return (1);
}

// sort_r rotaciona toda a array em sentido ANTI-horario <- 
// ra rb rr
int	sort_r_void(int total, void **array, void **swap, char c)
{
	if (c == 'a')
	{
		// TODO: Executa RA
		int top_a;
		top_a = last_p_array_void(total, array);
		ft_printf("r%c\n", c);
		rotate_array(total, array, "ccw");
		return (0);		
	}
	if (c == 'b')
	{
		// TODO: Executa RB
		int top_s;
		top_s = last_p_array_void(total, swap);
		ft_printf("r%c\n", c);
		rotate_array(total, swap, "ccw");
		return (0);		
	}
	if (c == 'r')
	{
		// TODO: Executa RR
		ft_printf("r%c\n", c);
		rotate_array(total, array, "ccw");
		rotate_array(total, swap, "ccw");
		return (0);
	}		
	return (1);
}

// sort_rr rotaciona toda a array em sentido HORARIO -> 
// rra rra rrr
int	sort_rr_void(int total, void **array, void **swap, char c)
{
	if (c == 'a')
	{
		// TODO: Executa RRA
		int top_a;
		top_a = last_p_array_void(total, array);
		ft_printf("rr%c\n", c);
		rotate_array(total, array, "cw");
		return (0);
	}
	if (c == 'b')
	{
		// TODO: Executa RRB
		int top_s;
		top_s = last_p_array_void(total, swap);
		ft_printf("rr%c\n", c);
		rotate_array(total, swap, "cw");
		return (0);
	}
	if (c == 'r')
	{
		// TODO: Executa RRR
		ft_printf("rr%c\n", c);
		rotate_array(total, array, "cw");
		rotate_array(total, swap, "cw");		
		return (0);		
	}		
	return (1);
}

// sort_p transfere os dados de do top do array para outro array 
// pa pb
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
