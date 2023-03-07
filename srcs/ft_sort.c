/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:07:26 by antthoma          #+#    #+#             */
/*   Updated: 2023/03/06 23:05:09 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void split_array(int total, void **array, void **swap)
{
	int	i;

	// Se for maior que 3 elementos ele realiza a quebra em duas colunas
	i = 0;
	if (total > 3)
	{
		while (i < total / 2)
		{
			sort_p_void(total, array, swap, 'b');
			i++;
		}
	}
}

void sort_1_array(int total, void **array, void **swap)
{
	int	top_a;

	// Checa para fazer rotação
	top_a = last_p_array_void(total, array);
	if (top_a != -1)
	{
		// Se o topo for maior que o ultimo, a rotação é ANTI-Horario <-
		if (*(int *)array[top_a] > *(int *)array[0])
		{
			ft_printf("%d > %d\n", *(int *)array[top_a], *(int *)array[0]);
			sort_rr_void(total, array, swap, 'a');
		}
	}	
}

// ft_sort_void é o CORE,
// Ele realiza as checagens e depois faz o sort trocando os valores de lugar no array
// para isso é chamado as funcoes sa ra rra
void	ft_sort_void(int total, void **array)
{
	int		i;
	int		top_a;
	int		top_s;
	void	**swap;

	swap = new_array_void(total);
	i = 0;
	
	// Se for maior que 3 elementos ele realiza a quebra wqem duas colunas
	split_array(total, array, swap);

	top_a = last_p_array_void(total, array);
	print_array_void(total, array, swap);
	i = 0;
	while (i < top_a)
	{	
		if (array[top_a] > array[top_a - 1])
		{
			sort_s_void(total, array, swap, 'a');
		}
		if (array[top_a] < array[0])
		{
			sort_r_void(total, array, swap, 'a');
		}
		i++;
	}
	i = 0;
	top_s = last_p_array_void(total, swap);
	while (i < top_s)
	{	
		if (swap[top_s] < swap[top_s - 1])
		{
			sort_s_void(total, array, swap, 'b');
		}
		top_a = last_p_array_void(total, array);
		if (swap[top_s] < array[top_a])
		{
			sort_p_void(total, array, swap, 'b');
		}
		i++;
	}
	print_array_void(total, array, swap);
	set_erease_void(total, swap);
	free(swap);
	return;
}
