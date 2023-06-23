/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:15:59 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/23 16:38:49 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_data)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_data;
	data = philo->data;
	while (get_time() < data->start_time)
		usleep(100);
	if (philo->id % 2 == 1 && data->philo_num > 1)
		usleep(data->time_to_eat * 100);
	while (1)
	{
		pthread_mutex_lock(&data->eat);
		if (philo->data->die_flag == TRUE || philo->eat_num >= data->num_must_eat)
		{
			pthread_mutex_unlock(&data->eat);
			break ;
		}
		pthread_mutex_unlock(&data->eat);
		eating(philo);
		if (check_dead_flag(philo) == FALSE)
			print_msg(philo, SLEEP_MSG, get_time() - data->start_time);
		sleeping(data->time_to_sleep, data);
		if (check_dead_flag(philo) == FALSE)
			print_msg(philo, THINK_MSG, get_time() - data->start_time);
	}
	return (NULL);
}

void	check_died(t_data *data)
{
	int	i;
	int	ate_count;

	i = 0;
	ate_count = 0;
	while (1)
	{
		i = 0;
		ate_count = 0;
		while (i < data->philo_num && data->die_flag == FALSE)
		{
			pthread_mutex_lock(&data->eat);
			if (get_time() > (unsigned long)data->philo[i].next_eat_time)
			{
				data->die_flag = TRUE;
				pthread_mutex_unlock(&data->eat);
				print_msg(&data->philo[i], DIED, get_time() - data->start_time);
				return ;
			}
			if (data->philo[i].eat_num >= data->num_must_eat)
				ate_count++;
			pthread_mutex_unlock(&data->eat);
			i++;
		}
		if (ate_count == data->philo_num)
			return ;
	}
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->eat);
	pthread_mutex_destroy(&data->write);
	free(data->philo);
	free(data->fork);
}

int	philo(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time() + 10;
	while (i < data->philo_num)
	{
		data->philo[i].next_eat_time += (int)data->start_time;
		if (pthread_create(&data->philo[i].th, NULL, &routine, &data->philo[i]) != 0)
			return (FALSE);
		i++;
	}
	check_died(data);
	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_join(data->philo[i].th, NULL) != 0)
			return (FALSE);
		i++;
	}
	destroy_mutex(data);
	return (TRUE);
}
