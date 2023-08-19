/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:15 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/19 21:42:26 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// constructor
DiamondTrap::DiamondTrap(/* args */)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	name_   = name;
	ClapTrap::name_ = name + "_clap_name";
	FlagTrap::hit_ = 100;
	ScavTrap::energy_ = 50;
	FlagTrap::attack_ = 30;
}

// destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &diamond)
{
	*this = diamond;
}

// copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond)
{
	if (this != &diamond)
	{
		name_   = diamond.name_;
		hit_    = diamond.hit_;
		energy_ = diamond.energy_;
		attack_ = diamond.attack_;
	}
	return (*this);
}

// method


void	DiamondTrap::whoAmI(void)
{
	std::cout << "Diamond name is " << name_ << ", ClapTrap name is " << ClapTrap::name_ << std::endl;
}

