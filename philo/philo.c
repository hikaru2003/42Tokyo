/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:15:59 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/18 18:40:54 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	if ((int)philo->id % 2 == 1 && philo->data->philo_num > 1)
		usleep(philo->data->time_to_eat / 2);
	while (philo->data->die_flag == FALSE && philo->eat_num < philo->data->num_must_eat)
	{
		eating(philo);
		print_msg(philo, SLEEP_MSG);
		sleeping(philo->data->time_to_sleep, philo->data);
		print_msg(philo, THINK_MSG);
	}
	return (NULL);
}

void	check_died(t_data *data)
{
	int	i;

	i = 0;
	while (data->philo[0].eat_num < data->num_must_eat)
	{
		i = 0;
		while (i < data->philo_num && data->die_flag == FALSE && data->philo[i].eat_num < data->num_must_eat)
		{
			pthread_mutex_lock(&data->eat);
			if (get_time() >= (unsigned long)data->philo[i].next_eat_time)
			{
				print_msg(&data->philo[i], DIED);
				data->die_flag = TRUE;
				exit(0);
			}
			pthread_mutex_unlock(&data->eat);
			i++;
		}
		if (data->die_flag == TRUE)
			break ;
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
