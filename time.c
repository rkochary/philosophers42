/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:59:07 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/23 21:04:16 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_thread(t_data *_data)
{
	struct timeval	tm;

	gettimeofday(&tm, 0);
	tm.tv_sec *= 1000;
	tm.tv_usec /= 1000;
	_data->time = (tm.tv_sec + tm.tv_usec) - _data->start;
	return (_data->time);
}

void	_timer(size_t tm)
{
	size_t	time;
	size_t	n_time;

	time = get_time();
	n_time = get_time();
	while ((n_time - time) < tm)
	{
		n_time = get_time();
		usleep(10);
	}
}

size_t	get_time(void)
{
	struct timeval	tm;
	size_t			time;

	gettimeofday(&tm, 0);
	time = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (time);
}
