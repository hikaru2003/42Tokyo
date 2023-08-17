/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:58:49 by hmorisak          #+#    #+#             */
/*   Updated: 2023/08/17 17:59:45 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	hikaru("hikaru");
	ClapTrap	mori("mori");

	hikaru.get_status();
	mori.get_status();
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
