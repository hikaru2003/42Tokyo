/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:03:16 by hikaru            #+#    #+#             */
/*   Updated: 2023/06/15 21:36:33 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	// take right fork:lock
	print_msg(FORK_MSG);
	// take left fork:lock
	print_msg(FORK_MSG);
}

void	drop_fork(t_philo *philo)
{
	// drop right and left forks:unlock
}

void	eating(t_philo *philo)
{
	take_fork(philo);
	print_msg(EAT_MSG);
	// start eating:usleep
	philo->eat_num++;
	drop_fork(philo);
}

void	sleeping(t_philo *philo)
{
	
}
