/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:58 by rkochary          #+#    #+#             */
/*   Updated: 2022/12/19 15:04:00 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_of_philo;
	int				time_of_die;
	int				time_of_eat;
	int				time_of_sleep;
	int				num_of_each_philo_eat;
	int				ind_struct;
	int				eat_count;
	int				died;
	size_t			last_ate_time;
	long int		time;
	unsigned long	start;
	pthread_t		th;
	pthread_mutex_t	*write;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}				t_data;

int				check_args(char **argv);
int				check_number(t_data *_data, char **argv);
void			ft_usleep(void);
void			*philo(void *data);
int				init_mutex(t_data *_data);
int				get_thread(t_data *_data);
size_t			get_time(void);
void			_timer(size_t tm);
size_t			time_thread(t_data *_data);
void			taking_forks(t_data *_data);
void			putting_forks(t_data *_data);
void			print(t_data *_data, int i);
int				is_died(t_data *_data, char **argv);
int				check_died(t_data *_data);
long int		ft_atoi(char *str);
int				check_arg_6(t_data *_data);
void			free_all(t_data *_data);

#endif