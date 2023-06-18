/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:27:08 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/18 18:41:18 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_param(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_int(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->die_flag = FALSE;
	data->num_must_eat = INT_MAX;
	if (argc == 6)
		data->num_must_eat = ft_atoi(argv[5]);
	if (data->philo_num == 0)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (FALSE);
	if (check_param(argc, argv, &data) == FALSE)
		return (FALSE);
	if (init_data(&data) == FALSE)
		return (FALSE);
	if (philo(&data) == FALSE)
		return (FALSE);
}
