/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:54:38 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 17:48:06 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	try
	{
		Zombie *horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			horde[i].set_name(name);
			horde[i].announce();
		}
		return (horde);
	}
	catch(std::bad_alloc)
	{
		std::cout << "malloc error\n";
		return (NULL);
	}
}