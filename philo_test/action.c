/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:16 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/23 16:40:31 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (unsigned long)1000 + time.tv_usec / 1000);
}

void	print_msg(t_philo *philo, char *str, unsigned long time)
{
	pthread_mutex_lock(&philo->data->write);
	pthread_mutex_lock(&philo->data->eat);
	if (philo->data->die_flag == TRUE && strcmp(str, DIED) != 0)
	{
		pthread_mutex_unlock(&philo->data->eat);
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	pthread_mutex_unlock(&philo->data->eat);
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

int	check_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat);
	if (philo->data->die_flag == TRUE)
	{
		pthread_mutex_unlock(&philo->data->eat);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->data->eat);
	return (FALSE);
}

void	take_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->fork[philo->right_fork]);
	if (check_dead_flag(philo) == FALSE)
		print_msg(philo, FORK_MSG, get_time() - data->start_time);
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	if (check_dead_flag(philo) == FALSE)
		print_msg(philo, FORK_MSG, get_time() - data->start_time);
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	take_fork(philo, data);
	if (check_dead_flag(philo) == FALSE)
		print_msg(philo, EAT_MSG, get_time() - data->start_time);
	pthread_mutex_lock(&data->eat);
	philo->next_eat_time = get_time() + data->time_to_die;
	philo->eat_num++;
	pthread_mutex_unlock(&data->eat);
	sleeping(data->time_to_eat, data);
	pthread_mutex_unlock(&data->fork[philo->right_fork]);
	pthread_mutex_unlock(&data->fork[philo->left_fork]);
}

//sleepingではタイムラグ起きないのでは、whileの条件を超えればいいから
void	sleeping(unsigned long time, t_data *data)
{
	unsigned long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(time);
		pthread_mutex_lock(&data->eat);
		if (data->die_flag == TRUE)
		{
			pthread_mutex_unlock(&data->eat);
			return ;
		}
		pthread_mutex_unlock(&data->eat);
	}
}
