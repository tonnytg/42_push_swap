/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:55:02 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/22 14:41:16 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	// int *array;
	// int total;
	// int	i;

	// total = argc - 1;
	// i = 1;
	// array = new_array(total);
	// while (i <= total)
	// {
	// 	push(array, argv[i][0]);
	// 	i++;
	// }
	// ft_sort(total, array);

	// Define um array de void
	void	**array1;
	int		i;
	int		total;

	total = argc - 1;
	array1 = new_array_void(total);
	// Imprime um array de void vazio
	ft_printf("\nInicio Array Vazio\n");
	print_array_void(total, array1);
	i = total;
	ft_printf("Total: %d\n", i);
	while (1 <= i)
	{
		// define cada valor em um void
		// TODO: Verificar que o ZERO forçado pode indicar que é o primeiro caracter
		// Isso causaria um bug, não pegando o onze por exemplo 11, apenas 1
		// 11 [0]=1 [1]=1
		push_void(total, array1, argv[i][0]);
		i--;
	}
	ft_printf("\nDepois de alimentar array void\n");
	print_array_void(total, array1);
	ft_sort_void(total, array1);
}
