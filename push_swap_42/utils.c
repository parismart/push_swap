/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:10:50 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 13:52:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min(t_data *data)
{
	int	i;
	int aux;

	i = 0;
	aux = data->a[0];
	while (++i < data->num_a)
	{
		if (aux > data->a[i])
		{
			aux = data->a[i];
			data->pivot_index = i;
		}
	}
	return (aux);
}

int		check_stack(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			break ;
	}
	if (i + 1 == data->num_a && !data->b)
		return (0);
	else
		return (1);
}

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