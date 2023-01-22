/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:56:11 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/23 21:03:42 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died(t_data *_data)
{
	size_t	tm;

	tm = get_time();
	tm -= _data->last_ate_time;
	if (tm >= (size_t)_data->time_of_die)
		return (-1);
	return (0);
}

int	is_died(t_data *_data, char **argv)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < _data->num_of_philo)
		{
			if (argv[5] && check_arg_6(_data) == -1)
				return (-1);
			if (check_died(&_data[i]) == -1)
			{
				print(&_data[i], 5);
				return (-1);
			}
			i++;
		}
	}
	return (0);
}

void	putting_forks(t_data *_data)
{
	pthread_mutex_unlock(_data->fork_right);
	pthread_mutex_unlock(_data->fork_left);
}

void	taking_forks(t_data *_data)
{
	pthread_mutex_lock(_data->fork_left);
	print(_data, 0);
	pthread_mutex_lock(_data->fork_right);
	print(_data, 0);
}
