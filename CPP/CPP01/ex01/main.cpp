/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:21:57 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 17:52:56 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *horde;
	horde = zombieHorde(5, "hikaru");
	delete[] (horde);
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q zombie");
// }