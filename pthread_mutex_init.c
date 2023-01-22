/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_mutex_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:55:03 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/23 21:04:08 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_thread(t_data *_data)
{
	int	i;

	i = 0;
	while (i < _data->num_of_philo)
	{
		_data[i].start = get_time();
		_data[i].write = _data[0].write;
		if ((pthread_create(&_data[i].th, 0, &philo, &_data[i])) == -1)
		{
			printf("Error: pthread_create function not working\n");
			return (-1);
		}
		pthread_detach(_data[i].th);
		i++;
	}
	usleep(10);
	return (0);
}

int	init_mutex(t_data *_data)
{
	int	i;

	i = 0;
	_data->fork = malloc(sizeof(pthread_mutex_t) * _data->num_of_philo);
	_data->write = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(_data->write, 0);
	while (i < _data[0].num_of_philo)
	{
		pthread_mutex_init(&_data->fork[i], 0);
		i++;
	}
	i = 0;
	while (i < _data[0].num_of_philo)
	{
		if ((i + 1) == _data[0].num_of_philo)
			_data[i].fork_left = &_data->fork[0];
		else
			_data[i].fork_left = &_data->fork[i + 1];
		_data[i].fork_right = &_data->fork[i];
		i++;
	}
	if (get_thread(_data) == -1)
		return (-1);
	return (0);
}
