/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:07:17 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/19 17:21:17 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

// constructor
FlagTrap::FlagTrap()
{
	std::cout << "FlagTrap Default constructor called" << std::endl;
}

FlagTrap::FlagTrap(std::string name)
{
	std::cout << "FlagTrap constructor called" << std::endl;
	name_   = name;
	hit_    = 100;
	energy_ = 100;
	attack_ = 30;
}

// destructor
FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap Destructor called" << std::endl;
}

// copy constructor
FlagTrap::FlagTrap(const FlagTrap &flag)
{
	*this = flag;
}

// copy assignment operator
FlagTrap &FlagTrap::operator=(const FlagTrap &flag)
{
	if (this != &flag)
	{
		name_   = flag.name_;
		hit_    = flag.hit_;
		energy_ = flag.energy_;
		attack_ = flag.attack_;
	}
	return (*this);
}

void	FlagTrap::attack(const std::string &target)
{
	if (energy_ <= 0)
		std::cout << "FlagTrap: no energy points left" << std::endl;
	else
	{
		energy_--;
		std::cout << "FlagTrap " << name_ << " attacks " << target << ", causing " << get_attack() << "points of damage!" << std::endl;
	}
}

void	FlagTrap::highFivesGuys(void)
{
	std::cout << "\33[33m" << name_ << " is a positive high fives request.\33[m" << std::endl;
}
