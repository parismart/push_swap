#include "checker.h"

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

static void	check_stacks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		i++;
	}
	if (data->b != NULL)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	ft_putstr_fd("OK\n", 1);
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
	int		ret;
	char	*line;
	int		i;

	data = NULL;
	if (!(argc - 1))
		ft_error(data);
	if (check_args(argc, argv))
		ft_error(data);
	data = init_values(data, argc, argv);
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = ft_gnl(0, &line);
		if (line[0] == '\0')
			ret = 0;
		else if (check_operations(line))
			ft_error(data);
		exec_operations(data, line);
		printf("STACK A ---> ");
		i = 0;
		while (i < data->num_a)
			printf("%i ", data->a[i++]);
		printf("\nSTACK B ---> ");
		i = 0;
		while (i < data->num_b)
			printf("%i ", data->b[i++]);
		printf("\n");
		free(line);
	}
	check_stacks(data);
	ft_exit(data);
	return (0);
}

//REVISAR MEMORY-LEAKS
