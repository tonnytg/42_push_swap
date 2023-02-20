/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/20 13:38:40 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(int *array, int total, int value)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	array[i] = value;
	printf("total: %d\n", total);
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
	push(array2, argc, 1);
	print_array(array1, argc);
	print_array(array2, argc);
	free(array1);
	free(array2);
	return (0);
}
