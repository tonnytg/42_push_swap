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
			return (1);
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sort_is_needed(int total, t_pair *array)
{
	int	i;

	if (is_long_int(total, array))
	{
		ft_printf("Error\n");
		exit (1);
	}
	if (is_duplicated(total, array))
	{
		ft_printf("Error\n");
		exit (1);
	}
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
		if (argv[i][0] != '-' && !ft_isdigit(argv[i][0]))
		{
			ft_printf("Error\n");
			exit (1);
		}
		if (argv[i][0] == '-' && argv[i][1] == '\0')
		{
			ft_printf("Error\n");
			exit (1);
		}
		i++;
	}
	return (0);
}
