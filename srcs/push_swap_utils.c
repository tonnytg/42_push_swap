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
	int *value_ptr1;
	int *value_ptr2;

	i = total - 1;
	while (i > 0) {
		if (array[i] != NULL && array[i - 1] != NULL) {
			value_ptr1 = array[i];
			value_ptr2 = array[i - 1];
			if ( value_ptr1[1] < value_ptr2[1])
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
