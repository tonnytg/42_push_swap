/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 13:59:28 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	void	**array;
	int		i;
	int		total;

	total = argc - 1;
	array = new_array_void(total);
	i = total;
	while (1 <= i)
	{
		push_void(total, array, ft_atoi(argv[i]));
		i--;
	}
	if (push_swap_needed(total, array))
	{
		ft_sort_void(total, array);	
	}
	set_erease_void(total, array);
	free(array);
}
