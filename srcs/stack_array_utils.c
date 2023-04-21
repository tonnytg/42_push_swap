/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:29:36 by antthoma          #+#    #+#             */
/*   Updated: 2023/03/06 22:54:09 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TODO: Avaliar se tem como retornar um ponteiro de ponteiro
void	*new_array_void(int total)
{
	void	**array;
	int	i;

	array = malloc(total * sizeof(void *));
	i = 0;
	// TODO: usar ft_caloc
	while (i < total)
	{
		array[i] = NULL;
		i++;
	}
	return (array);
}

void	reset_array_indice(int total, void **array)
{
	long int	*value_ptr;
	int	i;

	i = 0;
	while (i < total)
	{
		value_ptr = array[i];
		value_ptr[1] = 0;
		i++;
	}
}

int	last_p_array_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i <= total)
	{
		if (array[i] != NULL && array[i] != 0x0 && i != total)
			i++;
		else
			return (i - 1);
	}
	return (-1);
}
