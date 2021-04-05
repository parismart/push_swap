/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:10:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 11:10:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef	struct	s_data
{
	int			*a;
	int			*b;
	int			*aux;
	int			num_a;
	int			num_b;
	int			argc;
	char		**argv;
}				t_data;

t_data	*init_values(t_data *data, int argc, char **argv);
int		check_operations(char *line);
void	exec_operations(t_data *data, char *line);
void	swap(t_data *data, char c);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rotate(t_data *data, char c);
void	reverse_rotate(t_data *data, char c);
void	ft_error(t_data *data);

#endif