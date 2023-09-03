/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:54:38 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 15:30:56 by hikaru           ###   ########.fr       */
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
		}
		return (horde);
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << "bad_alloc" << e.what() << std::endl;
		return (NULL);
	}
}