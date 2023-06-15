/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:15:59 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/15 21:02:36 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	get_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (unsigned long)1000 + time.tv_sec / 1000);
}

void	print_msg(t_philo *philo, char *str)
{
	unsigned long	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write);
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	*routine(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	if ((int)philo->id % 2 == 1 && philo->data->philo_num > 1)	//(int)philo->id が正しくint型に変換できているか
		usleep(philo->data->time_to_eat / 2);
	while (philo->data->die_flag == FALSE || philo->eat_num < philo->data->num_must_eat)
	{
		eating(philo);
		print_msg(philo, SLEEP_MSG);
		sleeping(philo);
		print_msg(philo, THINK_MSG);
	}
	return (NULL);
}

int	philo(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = 	get_time();
	while (i < data->philo_num)
	{
		pthread_create(&data->philo[i].id, NULL, &routine, &data[i].philo);
		i++;
	}
	
}