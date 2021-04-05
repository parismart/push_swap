/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 12:03:53 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 13:12:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_100(t_data *data)
{
	algorithm_median(data);
	algorithm_push_a(data);
	algorithm_sort(data);
	algorithm_sort_a(data);
	algorithm_sort(data);
	algorithm_push_b(data, data->pivot_75);
	algorithm_reverse(data, data->pivot_75);
	algorithm_sort(data);
	data->pivot_87 = data->sort[data->index + (data->num_a - data->index) / 2];
	algorithm_push_b(data, data->pivot_87);
	algorithm_reverse(data, data->pivot_87);
	algorithm_sort(data);
	algorithm_push_b(data, data->sort[data->num_a - 1]);
	algorithm_sort(data);
}