/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:40:10 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/23 21:03:48 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *data)
{
	t_data	*_data;

	_data = data;
	_data->last_ate_time = get_time();
	if (_data->ind_struct % 2 == 0)
		usleep(100);
	while (1)
	{
		taking_forks(_data);
		_data->eat_count++;
		print(_data, 1);
		_timer(_data->time_of_eat);
		_data->last_ate_time = get_time();
		putting_forks(_data);
		print(_data, 2);
		_timer(_data->time_of_sleep);
		print(_data, 3);
	}
	return (0);
}

t_data	*init_arguments(char **argv)
{
	int		i;
	t_data	*_data;

	i = 0;
	_data = NULL;
	_data = malloc(sizeof(t_data) * ft_atoi(argv[1]));
	while (i < ft_atoi(argv[1]))
	{
		_data[i].num_of_philo = ft_atoi(argv[1]);
		_data[i].time_of_die = ft_atoi(argv[2]);
		_data[i].time_of_eat = ft_atoi(argv[3]);
		_data[i].time_of_sleep = ft_atoi(argv[4]);
		_data[i].ind_struct = i + 1;
		_data[i].eat_count = 0;
		_data[i].died = 0;
		if (argv[5])
			_data[i].num_of_each_philo_eat = ft_atoi(argv[5]);
		else
			_data[i].num_of_each_philo_eat = -1;
		i++;
	}
	return (_data);
}

int	main(int argc, char **argv)
{
	t_data	*_data;

	if (argc == 5 || argc == 6)
	{
		if (check_args(argv) == -1)
			return (-1);
		_data = init_arguments(argv);
		if (check_number(_data, argv) == -1)
			return (-1);
		if (init_mutex(_data) == -1)
		{
			free_all(_data);
			return (-1);
		}
		if (is_died(_data, argv) == -1)
		{
			free_all(_data);
			return (-1);
		}
	}
	else
		printf("Error: more or less arguments\n");
	return (0);
}
