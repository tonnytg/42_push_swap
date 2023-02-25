/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:07:26 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 02:16:11 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_void(int total, void **array)
{
	int		i;
	void	**swap;

	swap = new_array_void(total);
	i = 0;
	while (i < total / 2)
	{
		sort_p_void(total, array, swap, 'b');
		i++;
	}
	set_erease_void(total, swap);
	free(swap);
	return;
}
