/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:07:26 by antthoma          #+#    #+#             */
/*   Updated: 2023/03/04 21:58:02 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_sort_void é o CORE,
// Ele realiza as checagens e depois faz o sort trocando os valores de lugar no array
// para isso é chamado as funcoes sa ra rra
void	ft_sort_void(int total, void **array)
{
	int		i;
	int		top_a;
	int		top_s;
	void	**swap;

	swap = new_array_void(total);
	i = 0;
	// Se for maior que 3 elementos ele realiza a quebra em duas colunas
	if (total > 3)
	{
		while (i < total / 2)
		{
			sort_p_void(total, array, swap, 'b');
			i++;
		}
	}
	// Checa para fazer rotação
	top_a = last_p_array_void(total, array);
	if (top_a != -1)
	{
		// Se o topo for maior que o ultimo, a rotação é ANTI-Horario <-
		if (*(int *)array[top_a] > *(int *)array[0])
		{
			ft_printf("%d > %d\n", *(int *)array[top_a], *(int *)array[0]);
			sort_rr_void(total, array, swap, 'a');
		}
	}
	ft_printf("Array\n");
	print_array_void(total, array);
	ft_printf("Swap\n");
	print_array_void(total, swap);
	// // TODO: Válida alterações nas arrays,
	// // valida se vale a pena trocar só as primeiras variaveis top e top - 1
	top_a = last_p_array_void(total, array);
	if (top_a != -1)
	{
		if (array[top_a] > array[top_a - 1])
		{
			sort_s_void(total, array, swap, 'a');
		}
	}

	// // Checa para fazer rotação
	top_s = last_p_array_void(total, swap);
	if (top_s != -1)
	{
		// Se o topo for maior que o ultimo, a rotação é ANTI-Horario <-
		if (swap[top_s] < swap[0])
		{
			ft_printf("%d > %d\n", *(int *)swap[top_s], *(int *)swap[0]);
			sort_r_void(total, array, swap, 'b');
		}
	}

	top_s = last_p_array_void(total, swap);
	// // TODO: Bug quando tem só um elemento no array e você tenta checar com top - 1,
	// // da segment fault
	if (top_s != -1)
	{
		if (swap[top_s] < swap[top_s - 1])
		{
			sort_s_void(total, array, swap, 'b');
		}
	}

	top_s = last_p_array_void(total, swap);
	// // TODO: Bug quando tem só um elemento no array e você tenta checar com top - 1,
	// // da segment fault
	if (top_s != -1)
	{
		if (swap[top_s] > swap[top_s - 1])
		{
			sort_rr_void(total, array, swap, 'b');
		}
	}	

	// // TODO: Válida se vale a pena alterar anti-horário

	// // TODO: Válida se vale e pena alterar horário
	ft_printf("Array\n");
	print_array_void(total, array);
	ft_printf("Swap\n");
	print_array_void(total, swap);
	// // Retorna todo conteúdo
	top_s = last_p_array_void(total, swap);
	i = 0;
	while (i <= top_s)
	{
		sort_p_void(total, array, swap, 'a');
		i++;
	}
	ft_printf("Array Final\n");
	print_array_void(total, array);
	ft_printf("Swap Final\n");
	print_array_void(total, swap);
	set_erease_void(total, swap);
	free(swap);
	return;
}
