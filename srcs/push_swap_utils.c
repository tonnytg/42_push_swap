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

int is_long_int(int total, void **array)
{
	int i;
	long int *value_ptr;

	i = 0;
	while (i < total)
	{
		value_ptr = array[i];
		if (value_ptr[0] > MAX_INT || value_ptr[0] < MIN_INT)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int is_duplicated(int total, void **array)
{
	int i;
	int j;
	long int *value_ptr1;
	long int *value_ptr2;

	i = 0;
	while(i < total)
	{
		value_ptr1 = array[i];
		j = 0;
		while (j < total)
		{
			value_ptr2 = array[j];
			if (value_ptr1[0] == value_ptr2[0] && i != j)
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

int	push_swap_needed(int total, void **array)
{
	int	i;
	long int *value_ptr1;
	long int *value_ptr2;

	if (is_long_int(total, array))
		return (0);
	if (is_duplicated(total, array))
		return (0);
	i = total - 1;
	while (i > 0) {
		if (array[i] != NULL && array[i - 1] != NULL) {
			value_ptr1 = array[i];
			value_ptr2 = array[i - 1];
			if ( value_ptr1[1] > value_ptr2[1])
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
			&& !(argv[i][0] == '-'
			&& ft_strisdigit(&argv[i][1])))
			return (1);
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
			return (1);
		i++;
	}
	return (0);
}
