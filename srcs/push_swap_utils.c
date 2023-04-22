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

int is_long_int(int total, t_pair *array)
{
	int i;

	i = 0;
	while (i < total)
	{
		if (array[i].value > MAX_INT || array[i].value < MIN_INT)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int is_duplicated(int total, t_pair *array)
{
	int i;
	int j;

	i = 0;
	while(i < total)
	{
		j = 0;
		while (j < total)
		{
			if (array[i].value == array[j].value && i != j)
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	push_swap_needed(int total, t_pair *array)
{
	int	i;

	if (is_long_int(total, array))
		return (0);
	if (is_duplicated(total, array))
		return (0);
	i = total - 1;
	while (i > 0) {
		if (array[i].is_active != 0 && array[i - 1].is_active != 0) {
			if ( array[i].index > array[i - 1].index)
				return (1);
		}
		i--;
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
			&& (argv[i][0] != '-'
			&& ft_strisdigit(&argv[i][1])))
			return (1);
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
			return (1);
		i++;
	}
	return (0);
}
