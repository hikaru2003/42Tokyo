/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:15 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 21:04:05 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// constructor
DiamondTrap::DiamondTrap(/* args */) : ClapTrap("DiamondTrap_clap_name"), ScavTrap("DiamondTrap_clap_name"), FlagTrap("DiamondTrap_clap_name"), name_("DiamondTrap")
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->set_hit(FlagTrap::hit_);
	this->set_energy(ScavTrap::energy_);
	this->set_attack(FlagTrap::attack_);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FlagTrap(name + "_clap_name"), name_(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->set_hit(FlagTrap::hit_);
	this->set_energy(ScavTrap::energy_);
	this->set_attack(FlagTrap::attack_);
}

// destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &diamond) : ClapTrap(diamond), ScavTrap(diamond), FlagTrap(diamond), name_(diamond.get_name())
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = diamond;
}

// copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &diamond)
	{
		this->name_ = diamond.get_name();
		ClapTrap::operator=(diamond);

	}
	return (*this);
}

// method

std::string		DiamondTrap::get_name(void) const
{
	return (this->name_);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "\33[33m" << "Diamond name is " << this->get_name() << ", ClapTrap name is " << ClapTrap::get_name() << ".\33[m" << std::endl;
}

