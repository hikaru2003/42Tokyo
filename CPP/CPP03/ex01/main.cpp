/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:58:49 by hmorisak          #+#    #+#             */
/*   Updated: 2023/08/19 17:16:19 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	hikaru("hikaru");
	ScavTrap	mori("mori");

	hikaru.get_status();
	mori.get_status();
	mori.guardGate();
	hikaru.set_attack(6);
	mori.set_attack(4);
	
	hikaru.attack("mori");
	mori.takeDamage(hikaru.get_attack());
	mori.attack("hikaru");
	hikaru.takeDamage(mori.get_attack());
	hikaru.get_status();
	mori.get_status();

	hikaru.beRepaired(2);
	mori.beRepaired(1);
	hikaru.get_status();
	mori.get_status();

	return (0);
}
