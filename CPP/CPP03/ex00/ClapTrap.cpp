/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:02 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/04 14:36:33 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructor
ClapTrap::ClapTrap() : name_("ClapTrap"), hit_(10), energy_(10), attack_(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hit_(10), energy_(10), attack_(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &clap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = clap;
}

// copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &clap)
	{
		name_   = clap.get_name();
		hit_    = clap.get_hit();
		energy_ = clap.get_energy();
		attack_ = clap.get_attack();
	}
	return (*this);
}

// destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

// method
void	ClapTrap::attack(const std::string &target)
{
	if (energy_ <= 0)
		std::cout << "no energy points left" << std::endl;
	else
	{
		energy_--;
		std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << get_attack() << "points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_ < amount)
		hit_ = 0;
	else
		hit_ -= amount;
	std::cout << "ClapTrap " << name_ << " is attacked " << amount << " points, now " << get_hit() << "hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_ <= 0)
		std::cout << "no energy points left" << std::endl;
	else
	{
		energy_--;
		hit_ += amount;
		std::cout << "ClapTrap " << name_ << " is repaired " << amount << " points, now " << get_hit() << "hit points!" << std::endl;
	}
}


void	ClapTrap::get_status(void) const
{
	std::cout << "\033[31mShow Status" << std::endl;
	std::cout << "name   : " << name_ << std::endl;
	std::cout << "hit    : " << hit_ << std::endl;
	std::cout << "energy : " << energy_ << std::endl;
	std::cout << "attack : " << attack_ << std::endl;
	std::cout << "\33[m" << std::endl;
}

std::string	ClapTrap::get_name(void) const
{
	return (name_);
}

unsigned int	ClapTrap::get_attack(void) const
{
	return (attack_);
}

unsigned int	ClapTrap::get_hit(void) const
{
	return (hit_);
}

unsigned int	ClapTrap::get_energy(void) const
{
	return (energy_);
}

void	ClapTrap::set_attack(unsigned int amount)
{
	attack_ = amount;
}