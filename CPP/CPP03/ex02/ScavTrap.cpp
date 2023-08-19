/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:52 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/19 17:19:40 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	name_   = name;
	hit_    = 100;
	energy_ = 50;
	attack_ = 20;
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap &scav)
{
	*this = scav;
}

// copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &scav)
{
	if (this != &scav)
	{
		name_   = scav.name_;
		hit_    = scav.hit_;
		energy_ = scav.energy_;
		attack_ = scav.attack_;
	}
	return (*this);
}

// method
void	ScavTrap::attack(const std::string &target)
{
	if (energy_ <= 0)
		std::cout << "ScavTrap: no energy points left" << std::endl;
	else
	{
		energy_--;
		std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing " << get_attack() << "points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "\033[33m" << name_ << " is now in Gate keeper mode.\33[m" << std::endl;
}
