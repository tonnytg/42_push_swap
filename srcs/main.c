/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:13:52 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/21 20:25:57 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (check_values(argc, argv))
	{
		ft_printf("Error\n");
		exit (1);
	}
	push_swap(argc, argv);
	return (0);
}
