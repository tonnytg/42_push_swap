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

#include "push_swap.h"

void	set_erease_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		free(array[i]);
		i++;
	}
}

void	set_clean_void(int total, void **array)
{
	int	i;

	i = 0;
	while (i < total)
	{
		array[i] = NULL;
		i++;
	}
}

void	*new_array_void(int total)
{
	void **array;

	array = malloc(total * sizeof(void *));
	set_clean_void(total, array);
	return (array);	
}

void	print_array_void(int total, void **array, void **swap)
{
	int	i;

	i = 0;
	ft_printf("I\t|A\t|B\n");
	while (i < total)
	{
		ft_printf("[%d]",i);
		if (array[i] != NULL)
			ft_printf("\t|%d", *(int *)array[i]);
		else
			ft_printf("\t|%p", array[i]);
		if (swap[i] != NULL)
			ft_printf("\t|%d\n", *(int *)swap[i]);
		else
			ft_printf("\t|%p\n", swap[i]);
		// ft_printf("[%d]\t|%p|%p\n", i, array[i], swap[i]);
		i++;
	}
}

// Get max int do array
int	get_max_int_array(int total, void **array)
{
    int max;
	int i;
	
	max = *(int *)array[0];
	i = 1;
	while (i < total)
	{
		int num = *(int *)array[i];
        if (num > max)
        {
            max = num;
        }
		i++;
	}
    return max;
}



// rotate vai ficar responsavel por girar os valores dentro do array
// é um processo custoso porque precisa jogar o valor em uma variavel temporaria
// e depois realocar ela
void rotate_array(int total, void **array, char *option)
{
	int	i;
	int	top_a;
	void *tmp;
	// Sentdio Horario Clockwise
	if (ft_strcmp(option, "cw") == 0)
	{
		// TODO: Horário
		// ft_printf("CW\n");
		top_a = last_p_array_void(total, array);
		tmp = array[top_a];
		i = top_a;
		while (i > 0)
		{
			array[i] = array[i-1];
			i--;
		}
		array[0] = tmp;
		return;
	}
	if (ft_strcmp(option, "ccw") == 0)
	{
		// TODO: Anti-Horario
		// ft_printf("CCW\n");
		top_a = last_p_array_void(total, array);
		tmp = array[0];
		i = 0;
		while (i < top_a)
		{
			array[i] = array[i+1];
			i++;
		}
		array[top_a] = tmp;
		return;		
	}
	// TODO: Caso de errado
	ft_printf("Deu errado");
	exit (1);
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
