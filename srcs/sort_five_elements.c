/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:23:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/04/26 19:44:39 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_five_elements(int total, t_pair *array)
{
	int			trigger;
	t_pair		*swap;
	int			top;

	trigger = 0;
	swap = ft_calloc(total, sizeof(t_pair));
	move_stack(total, array, swap, 2);
	ft_sort_three_elements(total - trigger, array);
	top = last_p_array_void(total, swap);
	if (top >= 0)
		sort_p_void(total, array, swap, 'a');
	top = last_p_array_void(total, swap);
	if (top >= 0)
		sort_p_void(total, array, swap, 'a');
	free(swap);
}
