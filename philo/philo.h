/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:28:25 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/15 20:58:25 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 0
# define FALSE 1

# define FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"


typedef	struct s_philo
{
	t_data		*data;
	pthread_t	id;
	// int			pos;
	int			eat_num;
	int			next_eat_time;
	int			right_fork;
	int			left_fork;
}	t_philo;

typedef	struct s_data
{
	int				philo_num;
	int				start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				die_flag;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;


int		ft_atoi(const char *str);
int		is_int(char *str); //数字以外、マイナス、オーバーフローはFALSE




#endif