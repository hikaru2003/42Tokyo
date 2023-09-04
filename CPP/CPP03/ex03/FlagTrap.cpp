/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:07:17 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 16:18:22 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

// constructor
FlagTrap::FlagTrap()
{
	std::cout << "FlagTrap Default constructor called" << std::endl;
	name_   = "FragTrap";
	hit_    = 100;
	energy_ = 100;
	attack_ = 30;
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
	std::cout << "FlagTrap Copy constructor called" << std::endl;
	*this = flag;
}

// copy assignment operator
FlagTrap &FlagTrap::operator=(const FlagTrap &flag)
{
	std::cout << "FlagTrap Copy assignment operator called" << std::endl;
	if (this != &flag)
	{
		name_   = flag.get_name();
		hit_    = flag.get_hit();
		energy_ = flag.get_energy();
		attack_ = flag.get_attack();
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
