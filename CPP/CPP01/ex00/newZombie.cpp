/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:14 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 17:32:39 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name_ )
{
	try
	{
		Zombie *zombie = new Zombie(name_);
		zombie->announce();
		return (zombie);
	}
	catch(std::bad_alloc)
	{
		std::cout << "malloc error\n";
		return (NULL);
	}
}
