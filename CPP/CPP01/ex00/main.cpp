/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:10 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 17:21:46 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("newZombie");
	randomChump("randomChump");
	delete (zombie);
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q zombie");
// }
