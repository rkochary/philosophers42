/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:29:26 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/29 16:06:12 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (((arg[i][j] >= '0' && arg[i][j] <= '9') || arg[i][j] == ' ' ))
				j++ ;
			else
            {
                 printf("Error: character in arguments\n");
                return (1);
            }
		}
		i++;
	}
    return (0);
}

int check_num(char **str)
{
	int i;

	i = 1;
	while(str[i])
	{
		if (ft_atoi(str[i]) < 1)
		{
			printf("Error: wrong arguments\n");
			return (1);
		}
		i++;
	}
	return (0);
}