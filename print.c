/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:56:49 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/19 15:24:22 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_data *_data, int i)
{
	pthread_mutex_lock(_data->write);
	time_thread(_data);
	if (i == 5)
		printf("%ld:\tPhilosopher %d\t is died \n", \
				_data->time, _data->ind_struct);
	if (i == 0)
		printf("%ld:\tPhilosopher %d\t has taken a fork \n", \
				_data->time, _data->ind_struct);
	else if (i == 1)
		printf("%ld:\tPhilosopher %d\t is eating \n", \
				_data->time, _data->ind_struct);
	else if (i == 2)
		printf("%ld:\tPhilosopher %d\t is sleeping \n", \
				_data->time, _data->ind_struct);
	else if (i == 3)
		printf("%ld:\tPhilosopher %d\t is thinking \n", \
				_data->time, _data->ind_struct);
	else if (i == 4)
		printf("%ld:\t all ate %d times\n", _data->time,
			_data->num_of_each_philo_eat);
	pthread_mutex_unlock(_data->write);
}
