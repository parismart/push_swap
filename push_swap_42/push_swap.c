/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:10:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/05 13:05:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_exit(t_data *data)
{
	if (data != NULL)
	{
		if (data->a != NULL)
			free(data->a);
		if (data->b != NULL)
			free(data->b);
		free(data);
	}
	exit(0);
}

void		ft_error(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_exit(data);
}

static int	check_args(int argc, char **argv)
{
	int i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	*data;
	int		j;

	data = NULL;
	if (!(argc - 1))
		ft_error(data);
	if (check_args(argc, argv))
		ft_error(data);
	data = init_values(data, argc, argv);
	if (argc <= 6)
		algorithm_5(data);
	if (argc > 6)
		algorithm_100(data);
				printf("\nPIVOTS ---> %i, %i, %i",  data->pivot, data->pivot_75, data->pivot_87);
				printf("\nSTACK A ---> ");
				j = -1;
				while (++j < data->num_a)
					printf("%i ", data->a[j]);
				printf("\nSTACK B ---> ");
				j = -1;
				while (++j < data->num_b)
					printf("%i ", data->b[j]);
	ft_exit(data);
	return (0);
}
