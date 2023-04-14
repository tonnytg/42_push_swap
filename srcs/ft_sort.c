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

void ft_sort_two_void(int total, void **array)
{
		sort_s_void(total, array, NULL, 'a');
}

void ft_sort_three_void(int total, void **array)
{
	int	*value_ptr1;
	int	*value_ptr2;
	int	*value_ptr3;

	value_ptr1 = array[0];
	value_ptr2 = array[1];
	value_ptr3 = array[2];
	if (value_ptr1[0] > value_ptr2[0])
		sort_s_void(total, array, NULL, 'a');
	else if (value_ptr1[0] > value_ptr3[0])
	{
		sort_rr_void(total, array, NULL, 'a');
	}
}

void	ft_sort_void(int total, void **array)
{
	if (total == 2)
	{
		ft_sort_two_void(total, array);
		return ;
	}
	if (total == 3)
	{
		ft_sort_three_void(total, array);
		return ;
	}
	raddixsort(total, array);
	return ;
}
