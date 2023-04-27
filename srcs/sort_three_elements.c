#include "../includes/push_swap.h"

void	ft_sort_three_elements(int total, t_pair *array)
{
	int			i;

	i = 0;
	while (i < total)
	{
		if (array[2].index > array[0].index )
			sort_r_void(total, array, NULL, 'a');
		else if (array[1].index > array[0].index)
			sort_rr_void(total, array, NULL, 'a');
		else if (array[2].index > array[0].index)
			sort_r_void(total, array, NULL, 'a');
		else if (array[2].index > array[1].index)
			sort_s_void(total, array, NULL, 'a');
		i++;
	}
}
