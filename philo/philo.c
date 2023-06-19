/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:15:59 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/19 14:17:54 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_data)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philo_data;
	data = philo->data;
	if (philo->id % 2 == 1 && data->philo_num > 1)
		usleep(data->time_to_eat * 2);
	while (1)
	{
		pthread_mutex_lock(&data->dead);
		if (data->die_flag == TRUE)
			exit (0);
		pthread_mutex_unlock(&data->dead);
		pthread_mutex_lock(&data->eat);
		if (philo->eat_num >= data->num_must_eat)
			exit (0);
		pthread_mutex_unlock(&data->eat);
		eating(philo);
		print_msg(philo, SLEEP_MSG);
		sleeping(data->time_to_sleep, data);
		print_msg(philo, THINK_MSG);
	}
	return (NULL);
}

void	check_died(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < data->philo_num && data->die_flag == FALSE)
		{
			pthread_mutex_lock(&data->eat);
			// pthread_mutex_lock(&data->dead);
			if (get_time() >= (unsigned long)data->philo[i].next_eat_time)
			{
				print_msg(&data->philo[i], DIED);
				data->die_flag = TRUE;
			}
			if (data->philo[i].eat_num >= data->num_must_eat) //index=0のみ見ればいいのでは？一番下の行
				exit (0) ;
			// pthread_mutex_unlock(&data->dead);
			pthread_mutex_unlock(&data->eat);
			i++;
		}
		pthread_mutex_lock(&data->dead);
		if (data->die_flag == TRUE)
			exit (0) ;
		pthread_mutex_unlock(&data->dead);
		pthread_mutex_lock(&data->eat);
		if (data->philo[0].eat_num >= data->num_must_eat)
			exit (0) ;
		pthread_mutex_unlock(&data->eat);		
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
	data->start_time = get_time();
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
