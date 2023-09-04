/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:58:49 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/04 21:06:15 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	FlagTrap	hikaru("hikaru");
	ScavTrap	mori("mori");
	DiamondTrap	saki("saki");

	hikaru.get_status();
	mori.get_status();
	saki.get_status();
	
	mori.guardGate();
	hikaru.highFivesGuys();
	saki.whoAmI();
	
	hikaru.set_attack(6);
	mori.set_attack(4);
	saki.set_attack(10);
	
	hikaru.attack("saki");
	saki.takeDamage(hikaru.get_attack());
	saki.attack("hikaru");
	hikaru.takeDamage(saki.get_attack());
	hikaru.get_status();
	saki.get_status();

	hikaru.beRepaired(2);
	saki.beRepaired(1);
	hikaru.get_status();
	saki.get_status();

	return (0);
}
