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

void	raddixsort(int total, void **array, void **swap)
{
	ft_printf("Raddix Sort - Total:%d\n", total);
	ft_printf("Array: %p\n", array[0]);
	ft_printf("Swap: %p\n", swap[0]);
}

// ft_sort_void é o CORE,
// Ele realiza as checagens para a troca e depois faz o sort trocando os valores de lugar no array
// para isso é chamado as funcoes s r rr
void	ft_sort_void(int total, void **array)
{
	void	**swap;

	swap = new_array_void(total);
	split_array(total, array, swap);

	// Sort
	raddixsort(total, array, swap);

	set_erease_void(total, swap);
	free(swap);
	return;
}