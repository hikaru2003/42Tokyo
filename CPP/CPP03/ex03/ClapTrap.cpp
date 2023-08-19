/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:02 by hmorisak          #+#    #+#             */
/*   Updated: 2023/08/18 18:54:16 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructor
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	name_   = name;
	hit_    = 10;
	energy_ = 10;
	attack_ = 0;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap &clap)
{
	*this = clap;
}

// copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	if (this != &clap)
	{
		name_   = clap.name_;
		hit_    = clap.hit_;
		energy_ = clap.energy_;
		attack_ = clap.attack_;
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
		std::cout << "ClapTrap: no energy points left" << std::endl;
	else
	{
		energy_--;
		hit_ += amount;
		std::cout << "ClapTrap " << name_ << " is repaired " << amount << " points, now " << get_hit() << "hit points!" << std::endl;
	}
}


void	ClapTrap::get_status(void)
{
	std::cout << "\033[31mShow Status" << std::endl;
	std::cout << "name   : " << name_ << std::endl;
	std::cout << "hit    : " << hit_ << std::endl;
	std::cout << "energy : " << energy_ << std::endl;
	std::cout << "attack : " << attack_ << std::endl;
	std::cout << "\33[m" << std::endl;
}

unsigned int	ClapTrap::get_attack(void)
{
	return (attack_);
}

unsigned int	ClapTrap::get_hit(void)
{
	return (hit_);
}

unsigned int	ClapTrap::get_energy(void)
{
	return (energy_);
}

void	ClapTrap::set_attack(unsigned int amount)
{
	attack_ = amount;
}