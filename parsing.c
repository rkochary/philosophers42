/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:28:30 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/23 21:03:57 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number(t_data *_data, char **argv)
{
	if (_data->num_of_philo < 1 || _data->time_of_die < 1
		|| _data->time_of_eat < 1 || _data->time_of_sleep < 1
		|| (argv[5] && _data->num_of_each_philo_eat < 1))
	{
		printf("Error: wrong arguments\n");
		return (-1);
	}
	return (0);
}

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (ft_atoi(argv[i]) < 1)
		return (-1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				if (!(argv[i][j] == '-' || argv[i][j] == '+'))
				{
					printf("Error: character in arguments\n");
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
