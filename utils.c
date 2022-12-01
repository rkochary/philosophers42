/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:30:49 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/30 17:50:12 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoi(char *str)
{
	int			i;
	int			s;
	long int	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res < -2147483648 || res > 2147483647)
			return (-1);
		i++;
	}
	return (res * s);
}

t_data *create_args(char **av)
{
	t_data	*data;
	int		i;
	
	i = 0;
	data = NULL;
	data = malloc(sizeof(t_data));
		data->num_of_phil = ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_sleep = ft_atoi(av[3]);
		data->time_to_eat = ft_atoi(av[4]);
		data->thr = malloc(sizeof(pthread_t));
		if(av[5])
			data[i].each_must_eat_time = ft_atoi(av[5]);
		i++;
	return (data);
}

void *thread_func()
{
	while(1)
	{
		printf("anverj cikl");
	}
}

int create_philos(t_data *philos)
{
	int	i;

	i = 0;
	philos = malloc(sizeof(t_data) * philos->num_of_phil);
	while(i < philos->num_of_phil)
	{
		pthread_create(&philos[i].thr, NULL, thread_func , &philos[i]);
	}
}
