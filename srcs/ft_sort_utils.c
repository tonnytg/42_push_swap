/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:30:19 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/22 02:37:40 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort_s muda a posicão do array[0] com a posição[1]
// somente entre eles
int	sort_s(int *array, int *swap, char c)
{
	if (c == 'a')
	{
		// TODO: Executa SA
		ft_printf("s%c\n", c);
		return (0);		
	}
	if (c == 'b')
	{
		// TODO: Executa SB
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

// sort_r rotaciona toda a array em sentido ANTI-horario
int	sort_r(int *array, int *swap, char c)
{
	if (c == 'a')
	{
		// TODO: Executa RA
		ft_printf("r%c\n", c);
		return (0);		
	}
	if (c == 'b')
	{
		// TODO: Executa RB
		ft_printf("r%c\n", c);
		return (0);		
	}
	if (c == 'r')
	{
		// TODO: Executa RR
		ft_printf("r%c\n", c);
		return (0);
	}		
	return (1);
}

// sort_rr rotaciona toda a array em sentido HORARIO
int	sort_rr(int *array, int *swap, char c)
{
	if (c == 'a')
	{
		// TODO: Executa RRA
		ft_printf("rr%c\n", c);
		return (0);
	}
	if (c == 'b')
	{
		// TODO: Executa RRB
		ft_printf("rr%c\n", c);	
		return (0);		
	}
	if (c == 'r')
	{
		// TODO: Executa RRR
		ft_printf("rr%c\n", c);
		return (0);		
	}		
	return (1);
}

int	sort_p(int *array, int *swap, char c)
{
	int cache;

	if (c == 'a')
	{
		cache = pop(swap);
		push(array, cache);
		ft_printf("p%c\n", c);
		return (0);		
	}
	if (c == 'b')
	{
		cache = pop(array);
		push(swap, cache);
		ft_printf("p%c\n", c);
		return (0);
	}
	return (1);
}

int	sort_p_void(int **array, int **swap, char c)
{
	int cache;

	if (c == 'a')
	{
		cache = pop(swap);
		push(array, cache);
		ft_printf("p%c\n", c);
		return (0);		
	}
	if (c == 'b')
	{
		cache = pop(array);
		push(swap, cache);
		ft_printf("p%c\n", c);
		return (0);
	}
	return (1);
}
