/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:15 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 16:17:41 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// constructor
DiamondTrap::DiamondTrap(/* args */) : ClapTrap("DiamondTrap_clap_name"), ScavTrap("DiamondTrap"), FlagTrap("DiamondTrap"), name_("DiamondTrap")
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	hit_    = FlagTrap::hit_;
	energy_ = ScavTrap::energy_;
	attack_ = FlagTrap::attack_;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FlagTrap(name), name_(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	hit_    = FlagTrap::hit_;
	energy_ = ScavTrap::energy_;
	attack_ = FlagTrap::attack_;
	std::cout << "hit, energy, attack -> " << ClapTrap::hit_ << ", " << ClapTrap::energy_ << ", " << ScavTrap::attack_ << std::endl;
}

// destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &diamond)
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
		name_   = diamond.get_name();
		hit_    = diamond.get_hit();
		energy_ = diamond.get_energy();
		attack_ = diamond.get_attack();
	}
	return (*this);
}

// method

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "\33[33m" << "Diamond name is " << name_ << ", ClapTrap name is " << ClapTrap::name_ << ".\33[m" << std::endl;
}

