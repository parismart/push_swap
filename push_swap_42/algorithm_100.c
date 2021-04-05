/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:10:20 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 12:01:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_median(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->pivot_index)
	{
		if (data->a[0] <= data->pivot)
		{
			push_b(data);
			ft_putstr_fd("pb\n", 1);
			i++;
		}
		else if (data->a[0] > data->pivot)
		{
			rotate(data, 'a');
			ft_putstr_fd("ra\n", 1);
		}
	}
	parser_stack(data, data->num_a, data->a);
	data->pivot_75 = data->pivot;
}

void	algorithm_push_a(t_data *data)
{
	int	i;
	int	x;

	i = 0;
	x = data->num_b / 2;
	parser_stack(data, data->num_b, data->b);
	while (data->b && i <= x)
	{
		if (data->b[0] == data->sort[data->index])
		{
			push_a(data);
			rotate(data, 'a');
			ft_putstr_fd("pa\nra\n", 1);
			data->index++;
		}
		else if (data->b[0] >= data->pivot)
		{
			push_a(data);
			ft_putstr_fd("pa\n", 1);
			i++;
		}
		else if (data->b[0] < data->pivot)
		{
			rotate(data, 'b');
			ft_putstr_fd("rb\n", 1);
		}
	}
}

void	algorithm_sort_a(t_data *data)
{
	if (!check_stack(data))
		return ;
	parser_stack(data, data->num_a, data->a);
	while (data->a[0] <= data->pivot)
	{
		if (data->a[0] == data->sort[data->index])
		{
			rotate(data, 'a');
			ft_putstr_fd("ra\n", 1);
			data->index++;
		}
		else
		{		
			push_b(data);
			ft_putstr_fd("pb\n", 1);
		}
	}
}

void	algorithm_push_b(t_data *data, int pivot)
{
	parser_stack(data, data->num_a, data->a);
	while (data->a[0] != data->sort[0])
	{
		if (data->a[0] > pivot)
		{
			rotate(data, 'a');
			ft_putstr_fd("ra\n", 1);
		}
		else
		{
			push_b(data);
			ft_putstr_fd("pb\n", 1);
		}
	}
}

void	algorithm_reverse(t_data *data, int pivot)
{
	parser_stack(data, data->num_a, data->a);
	while (data->a[data->num_a - 1] != data->sort[data->index - 1])
	{
		if (data->b[0] != pivot)
		{
			reverse_rotate(data, 'c');
			ft_putstr_fd("rrr\n", 1);
		}
		else
		{
			reverse_rotate(data, 'a');
			ft_putstr_fd("rra\n", 1);
		}
	}
	while (data->b && data->b[0] != pivot)
	{
		reverse_rotate(data, 'c');
		ft_putstr_fd("rrb\n", 1);
	}
}