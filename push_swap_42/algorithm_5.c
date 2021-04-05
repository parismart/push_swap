/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:07:27 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 13:54:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_a(t_data *data)
{
	int	i;
	int aux;

	i = 0;
	aux = data->a[0];
	while (++i < data->num_a)
	{
		if (aux < data->a[i])
		{
			aux = data->a[i];
			data->pivot_index = i;
		}
	}
	return (aux);
}

static int	stack_a(t_data *data)
{
	int i;
	i = -1;
	while (++i < data->num_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			break ;
	}
	return (i);
}

static int	check_finish(t_data *data)
{
	int	flag;

	flag = 0;
	if (stack_a(data) == data->num_a - 1)
	{
		while(data->num_b)
		{
			push_a(data);
			ft_putstr_fd("pa\n", 1);
		}
		flag = 1;
	}
	return (flag);
}

static void	algorithm_sort_5(t_data *data)
{
	get_min(data);
	if (data->num_a > 1 && data->a[1] < data->a[0])
	{
		swap(data, 'a');
		ft_putstr_fd("sa\n", 1);
	}
	else if (data->a[0] == data->sort[data->index])
	{
		push_b(data);
		ft_putstr_fd("pb\n", 1);
		data->index++;
	}
	else if ((float)data->pivot_index / (float)data->num_a > 0.5)
	{
		reverse_rotate(data, 'a');
		ft_putstr_fd("rra\n", 1);
	}
	else if ((float)data->pivot_index / (float)data->num_a <= 0.5)
	{
		rotate(data, 'a');
		ft_putstr_fd("ra\n", 1);
	}
}

void		algorithm_5(t_data *data)
{
	while(check_stack(data))
	{
		if (data->a[0] == get_max_a(data))
		{
			rotate(data, 'a');
			ft_putstr_fd("ra\n", 1);
		}
		if (check_finish(data))
			break ;
		else
			algorithm_sort_5(data);
	}
}