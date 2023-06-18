/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:16 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/18 18:41:57 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (unsigned long)1000 + time.tv_usec / 1000);
}

void	print_msg(t_philo *philo, char *str)
{
	unsigned long	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	take_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->fork[philo->right_fork]);
	print_msg(philo, FORK_MSG);
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	print_msg(philo, FORK_MSG);
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	take_fork(philo, data);
	print_msg(philo, EAT_MSG);
	pthread_mutex_lock(&data->eat);
	philo->next_eat_time = get_time() + data->time_to_die;
	pthread_mutex_unlock(&data->eat);
	sleeping(data->time_to_eat, data);
	philo->eat_num++;
	pthread_mutex_unlock(&data->fork[philo->right_fork]);
	pthread_mutex_unlock(&data->fork[philo->left_fork]);
}

void	sleeping(unsigned long time, t_data *data)
{
	unsigned long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(time);
		if (data->die_flag == TRUE)
			break ;
	}
}
