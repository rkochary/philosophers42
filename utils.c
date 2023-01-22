/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:57:39 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/23 21:04:20 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *_data)
{
	int	i;

	i = 0;
	if (_data->write)
		free(_data->write);
	while (i < _data->num_of_philo)
	{
		pthread_mutex_destroy(&_data->fork[i]);
		i++;
	}
	if (_data->fork)
		free(_data->fork);
	if (_data)
		free(_data);
}

int	check_arg_6(t_data *_data)
{
	int	i;

	i = 0;
	while (i < _data->num_of_philo)
	{
		if (_data[i].eat_count >= _data[i].num_of_each_philo_eat)
			_data[i].died = -1;
		i++;
	}
	i = 0;
	while (i < _data->num_of_philo)
	{
		if (_data[i].died == -1)
			i++;
		else
			return (0);
	}
	return (-1);
}

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
