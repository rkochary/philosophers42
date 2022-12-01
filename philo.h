/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:33:02 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/30 17:40:24 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_data   t_data;
typedef struct s_philo   t_philo;
struct s_data
{
    int             id;
    int             num_of_phil;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             each_must_eat_time;
    pthread_mutex_t *fork;
    pthread_mutex_t write;
    pthread_t        thr;
};

struct s_philo
{
    int             time_to_eat;
    int             time_to_sleep;
    int             must_eat_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t write;
};

int         check_arg(char **argv);
int         check_num(char **num);
long int	ft_atoi(char *str);
t_data      *create_args(char **av);

#endif