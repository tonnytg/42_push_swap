/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:07:26 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/28 03:19:10 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_void(int total, void **array)
{
	int		i;
	int		top_a;
	int		top_s;
	void	**swap;

	swap = new_array_void(total);
	i = 0;
	if (total > 3)
	{
		while (i < total / 2)
		{
			sort_p_void(total, array, swap, 'b');
			i++;
		}		
	}

	// TODO: Válida alterações nas arrays, valida se vale a pena rodar só as primeiras
	top_a = last_p_array_void(total, array);
	if ( (top_a - 1 >= 0) && array[top_a] > array[top_a - 1])
	{
		sort_s_void(total, array, swap, 'a');
	}
	top_s = last_p_array_void(total, swap);
	// TODO: Bug quando tem só um elemento no array e você tenta checar com top - 1,
	// da segment fault
	if ( (top_s - 1 >= 0) && swap[top_s] > swap[top_s - 1])
	{
		sort_s_void(total, array, swap, 'b');
	}

	// TODO: Válida se vale a pena alterar anti-horário

	// TODO: Válida se vale e pena alterar horário


	set_erease_void(total, swap);
	free(swap);
	return;
}
