/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/18 13:43:57 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(int *a, int *b)
{
	int swp;

	swp = a[0];
	a[0] = a[1];
	a[1] = swp;
}

void ft_sb(int *a, int *b)
{
	int swp;

	swp = b[0];
	b[0] = b[1];
	b[1] = swp;
}

void increment(int *x, int i, int v)
{
	if (v == 0)
		return;
	if (x[i] != 0)
		increment(x, i, v);
	else
	{
		x[i] = v;
		v = 0;
		return;	
	}
}

void ft_pa(int *a, int *b)
{
	if (b[0] != 0)
		
	b[0] = a[0];
}

int main(int argc, char **argv)
{
	int a[6];
	int b[6];

	
	return (0);
}