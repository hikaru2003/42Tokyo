/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:52 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 19:06:31 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->set_name("ScavTrap");
	this->set_attack(attack_);
	this->set_energy(energy_);
	this->set_hit(hit_);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->set_attack(attack_);
	this->set_energy(energy_);
	this->set_hit(hit_);
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap &scav)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = scav;
}

// copy assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &scav)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &scav)
		ClapTrap::operator=(scav);
	return (*this);
}

// method
void	ScavTrap::attack(const std::string &target)
{
	if (this->get_energy() <= 0)
		std::cout << "ScavTrap: no energy points left" << std::endl;
	else
	{
		this->set_energy(this->get_energy() - 1);
		std::cout << "ScavTrap " << this->get_name() << " attacks " << target << ", causing " << get_attack() << "points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "\033[33m" << this->get_name() << " is now in Gate keeper mode.\33[m" << std::endl;
}
