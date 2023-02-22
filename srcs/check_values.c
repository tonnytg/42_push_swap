/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:23:45 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/21 16:07:38 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_values(int total, char **values)
{
	int	i;
	int check_v;
	int result;

	if (total < 2)
		return (1);
	i = 1;
	while (i < total)
	{
		if (! ft_isdigit(values[i][0]))
			return (1);
		i++;
	}
	return (0);
}
