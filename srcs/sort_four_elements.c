#include "../includes/push_swap.h"

long int find_min(int total, t_pair *array)
{
	int i;
	int min;

	i = 0;
	min = MAX_INT;
	while (i < total)
	{
		if (array[i].is_active != 0)
		{
			if (array[i].index < min)
				min = array[i].index;
		}
		i++;
	}
	return (min);
}

void	ft_sort_four_elements(int total, t_pair *array)
{
	int i;
	int trigger;
	long int min;
	t_pair *swap;
	int top_a;

	trigger = 0;
	swap = ft_calloc(total, sizeof(t_pair));
	i = 0;
	while (trigger < 1)
	{
		top_a = last_p_array_void(total, array);
		min = find_min(total, array);
		if (array[top_a].index == min)
		{
			sort_p_void(total, array, swap, 'b');
			trigger++;
		}
		else
		{
			sort_r_void(total, array, swap, 'a');
		}
		i++;
	}
	ft_sort_three_elements(total - trigger, array);
	int top_b = last_p_array_void(total, swap);
	if (top_b >= 0)
		sort_p_void(total, array, swap, 'a');
	top_b = last_p_array_void(total, swap);
	if (top_b >= 0)
		sort_p_void(total, array, swap, 'a');
}
