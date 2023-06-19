/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:16 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/19 21:31:18 by hikaru           ###   ########.fr       */
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
	unsigned long	time, t1, t2;

	pthread_mutex_lock(&philo->data->eat);
	time = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->eat);
	t1 = get_time();
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
	if (strcmp(str, DIED) == 0)
		return ;
	t2 = get_time();
	pthread_mutex_lock(&philo->data->eat);
	philo->start_time += t2 - t1;
	philo->next_eat_time += t2 - t1;
	pthread_mutex_unlock(&philo->data->eat);
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
		print_msg(philo, FORK_MSG);
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	if (check_dead_flag(philo) == FALSE)
		print_msg(philo, FORK_MSG);
}

void	eating(t_philo *philo)
{
	t_data	*data;
	unsigned long	time_rug;

	data = philo->data;
	take_fork(philo, data);
	if (check_dead_flag(philo) == FALSE)
		print_msg(philo, EAT_MSG);
	pthread_mutex_lock(&data->eat);
	philo->next_eat_time = get_time() + data->time_to_die;
	philo->eat_num++;
	pthread_mutex_unlock(&data->eat);
	time_rug = sleeping(data->time_to_eat, data);
	pthread_mutex_lock(&data->eat);
	philo->next_eat_time += time_rug;
	philo->start_time += time_rug;
	pthread_mutex_unlock(&data->eat);
	pthread_mutex_unlock(&data->fork[philo->right_fork]);
	pthread_mutex_unlock(&data->fork[philo->left_fork]);
}

unsigned long	sleeping(unsigned long time, t_data *data)
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
			break ;
		}
		pthread_mutex_unlock(&data->eat);
	}
	return (get_time() - start - time);
}
