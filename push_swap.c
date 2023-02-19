/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/18 13:43:57 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_clean(int *array, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		array[i] = -1;
		i++;
	}
}

int	*new_array(int total)
{
	int	*array;

	array = malloc(sizeof(int) * total);
	set_clean(array, total);
	return (array);
}

void	print_array(int *array, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		printf("[%d] - %d\n", i, array[i]);
		i++;
	}
}

void push(int *array, int total, int value)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	array[i] = value;
}

int	main(int argc, char **argv)
{
	int	*array1;
	int	*array2;
	int	i;

	i = 1;
	while (argv[i])
	{
		printf("[%d] - %s\n", i, argv[i]);
		i++;
	}

	printf("\nStart\n");
	array1 = new_array(argc);
	array2 = new_array(argc);
	i = 1;
	push(array2, argc, 1);
	print_array(array1, argc);
	print_array(array2, argc);
	free(array1);
	free(array2);
	return (0);
}
