/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:07:17 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 19:06:04 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

// constructor
FlagTrap::FlagTrap() : ClapTrap()
{
	std::cout << "FlagTrap Default constructor called" << std::endl;
	this->set_name("FragTrap");
	this->set_attack(attack_);
	this->set_energy(energy_);
	this->set_hit(hit_);
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FlagTrap constructor called" << std::endl;
	this->set_attack(attack_);
	this->set_energy(energy_);
	this->set_hit(hit_);
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
		ClapTrap::operator=(flag);
	return (*this);
}

void	FlagTrap::attack(const std::string &target)
{
	if (this->get_energy() <= 0)
		std::cout << "FlagTrap: no energy points left" << std::endl;
	else
	{
		this->set_energy(this->get_energy() - 1);
		std::cout << "FlagTrap " << this->get_name() << " attacks " << target << ", causing " << get_attack() << "points of damage!" << std::endl;
	}
}

void	FlagTrap::highFivesGuys(void)
{
	std::cout << "\33[33m" << this->get_name() << " is a positive high fives request.\33[m" << std::endl;
}
