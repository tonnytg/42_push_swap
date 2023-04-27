#include "../includes/push_swap.h"

void	ft_sort_five_elements(int total, t_pair *array)
{
	int i, trigger;
	long int min;
	t_pair *swap;
	int top_a;

	trigger = 0;
	swap = ft_calloc(total, sizeof(t_pair));
	i = 0;
	while (trigger < 2)
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
			sort_rr_void(total, array, swap, 'a');
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
	free(swap);
}
