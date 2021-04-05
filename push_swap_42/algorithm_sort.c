#include "push_swap.h"

static int	get_pivot(t_data *data)
{
	int	i;
	int aux;

	data->aux = (int *)ft_calloc(data->num_b, sizeof(int));
	i = 0;
	aux = data->b[0];
	while (++i < data->num_b && data->b[i])
	{
		if (aux < data->b[i])
		{
			aux = data->b[i];
			data->pivot_index = i;
		}
	}
	return (aux);
}

static void check_push_reverse(t_data *data, int pivot)
{
	if (data->b[0] == data->sort[data->index])
	{
		push_a(data);
		ft_putstr_fd("pa\n", 1);
	}
	else if (data->b[0] == pivot)
	{
		push_a(data);
		ft_putstr_fd("pa\n", 1);
		get_pivot(data);
		pivot = data->b[data->index];
	}
	else if (data->b[0] != pivot)
	{
		if ((float)data->pivot_index / (float)data->num_b > 0.5)
		{
			reverse_rotate(data, 'b');
			ft_putstr_fd("rrb\n", 1);
		}
		else if ((float)data->pivot_index / (float)data->num_b <= 0.5)
		{
			rotate(data, 'b');
			ft_putstr_fd("rb\n", 1);
		}
	}
}

static void check_rotate(t_data *data, int pivot)
{
	if (data->a[0] == data->sort[data->index] && data->b[0] != pivot && 
		(float)data->pivot_index / (float)data->num_b <= 0.5)
	{
		rotate(data, 'c');
		ft_putstr_fd("rr\n", 1);
		data->index++;
	}
	if (data->a[0] == data->sort[data->index])
	{
		rotate(data, 'a');
		ft_putstr_fd("ra\n", 1);
		data->index++;
	}
}

void	algorithm_sort(t_data *data)
{
	int	pivot;

	parser_stack(data, data->num_b, data->b);
	while (data->num_b)
	{
		pivot = get_pivot(data);
		check_rotate(data, pivot);
		check_push_reverse(data, pivot);
	}
	while (data->a[0] == data->sort[data->index])
	{
		rotate(data, 'a');
		ft_putstr_fd("ra\n", 1);
		data->index++;
	}
}