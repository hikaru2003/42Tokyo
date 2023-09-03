/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:14 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 15:30:40 by hikaru           ###   ########.fr       */
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
	catch(const std::bad_alloc &e)
	{
		std::cerr << "bad_alloc" << e.what() << std::endl;
		return (NULL);
	}
}
