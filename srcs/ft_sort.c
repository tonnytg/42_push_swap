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

// ft_sort_void é o CORE,
// Ele realiza as checagens para a troca e depois faz o sort trocando os valores de lugar no array
// para isso é chamado as funcoes s r rr
void	ft_sort_void(int total, void **array)
{
	ft_printf("sort accepted\n");
	raddixsort(total, array);

	return;
}
