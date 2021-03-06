/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:10:42 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 13:52:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef	struct	s_data
{
	int			*a;
	int			*b;
	int			*aux;
	int			*sort;
	int			index;
	int			pivot_index;
	int			pivot;
	int			pivot_75;
	int			pivot_87;
	int			num_a;
	int			num_b;
	int			argc;
	char		**argv;
}				t_data;

t_data	*init_values(t_data *data, int argc, char **argv);
void	parser_stack(t_data *data, int num, int *stack);
int		check_stack(t_data *data);
int		get_min(t_data *data);
void	sort(t_data *data, int num, int *stack);
void	algorithm_5(t_data *data);
void	algorithm_100(t_data *data);
void	algorithm_median(t_data *data);
void	algorithm_push_a(t_data *data);
void	algorithm_sort(t_data *data);
void	algorithm_sort_a(t_data *data);
void	algorithm_push_b(t_data *data, int pivot);
void	algorithm_reverse(t_data *data, int pivot);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	swap(t_data *data, char c);
void	reverse_rotate(t_data *data, char c);
void	rotate(t_data *data, char c);
void	ft_error(t_data *data);

#endif