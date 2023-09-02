/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:21:57 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 17:31:59 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;
	int	n = 5;
	
	horde = zombieHorde(n, "hikaru");
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	
	delete[] (horde);
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q zombie");
// }