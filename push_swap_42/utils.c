#include "push_swap.h"

void	sort(t_data *data, int num, int *stack)
{
	int	i;
	int	j;
	int aux;

	i = -1;
	while (++i < num)
	{
		j = -1;
		while (++j < num - 1)
		{
			if (stack[j] > stack[j + 1])
			{
				aux = stack[j];
				stack[j] = stack[j + 1];
				stack[j + 1] = aux;
			}
		}
	}
}

void	parser_stack(t_data *data, int num, int *stack)
{
	int	i;

	data->aux = (int *)ft_calloc(num, sizeof(int));
	i = -1;
	while (++i < num)
		data->aux[i] = stack[i];
	sort(data, num, data->aux);
	if ((float)(num % 2) == 0.0)
		data->pivot_index = (num / 2) - 1;
	else
		data->pivot_index = num / 2;
	data->pivot = data->aux[data->pivot_index];
}
