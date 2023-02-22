/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:20:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/02/22 15:39:03 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(int *array, int value)
{
	int i;

	i = 0;
	while (array[i] != -1)
	{
		i++;
	}
	// TODO: Se o valor for excedido talvez deva dar um erro
	// talvez criar uma posição a mais e armazenar um nulo.
	array[i] = value;
}

void push_void(int total, void **array, int value)
{
	int *value_ptr;
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	if (i == total)
	{
		ft_printf("Panic, array it is full");
		exit (1);
	}
	// TODO: Se o valor for excedido talvez deva dar um erro
	// talvez criar uma posição a mais e armazenar um nulo.
    value_ptr = malloc(sizeof(int));
    *value_ptr = value;
    array[i] = value_ptr;
	ft_printf("Valor salvo: %d - Em: %p\n", value, array[i]);
}

int	pop(int *array)
{
	int i;
	int top;

	i = 0;
	while (array[i] != -1)
	{
		i++;
	}
	// TODO: Necessário criar um nulo, para que o POP
	// saiba quando pegar o TOP mesmo com a array cheia
	top = array[i - 1];
	array[i - 1] = -1;
	return (top);
}

int	pop_void(int total, void **array)
{
	int	i;
	int	top;

	i = 0;
	while (array[i] != NULL && i < total)
	{
		i++;
	}
	ft_printf("posição descoverta: %d\n", i);
	ft_printf("vai usar: %d\n", i - 1);
	// TODO: Necessário criar um nulo, para que o POP
	// saiba quando pegar o TOP mesmo com a array cheia
	top = *(int *)array[i - 1];
	array[i - 1] = NULL;
	return (top);
}

int	peek(int *array)
{
	int i;

	i = 0;
	// TODO: Criar um slot na Array para nulo
	while (array[i] != -1)
	{
		i++;
	}
	return array[i - 1];
}
