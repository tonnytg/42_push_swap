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

#include "../includes/push_swap.h"

int	push_swap_needed(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total - 1)
	{
		if (array[i] != NULL && array[i + 1] != NULL)
		{
			if (*(int *)array[i] < *(int *)array[i + 1])
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_values(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (!ft_strisdigit(argv[i])
			&& !(argv[i][0] == '-'
			&& ft_strisdigit(&argv[i][1])))
			return (1);
		i++;
	}
	return (0);
}
