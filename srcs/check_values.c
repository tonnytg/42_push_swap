/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:23:45 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 03:11:08 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_values(int total, char **values)
{
	int	i;

	if (total < 2)
		return (1);
	i = 1;
	while (i < total)
	{
		if (!ft_strisdigit(values[i])
			&& !(values[i][0] == '-'
			&& ft_strisdigit(&values[i][1])))
			return (1);
		i++;
	}
	return (0);
}
