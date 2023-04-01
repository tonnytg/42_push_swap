/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:13:52 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/25 03:12:53 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: Realizar os ajustes para limpeza de memória

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (check_values(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	push_swap(argc, argv);
	return (0);
}
