/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:02 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/04 21:03:49 by hikaru           ###   ########.fr       */
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
		name_   = clap.ClapTrap::get_name();
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
		std::cout << "ClapTrap " << this->get_name() << " attacks " << target << ", causing " << get_attack() << "points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_ < amount)
		hit_ = 0;
	else
		hit_ -= amount;
	std::cout << "ClapTrap " << this->get_name() << " is attacked " << amount << " points, now " << get_hit() << "hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_ <= 0)
		std::cout << "no energy points left" << std::endl;
	else
	{
		energy_--;
		hit_ += amount;
		std::cout << "ClapTrap " << this->get_name() << " is repaired " << amount << " points, now " << get_hit() << "hit points!" << std::endl;
	}
}


void	ClapTrap::get_status(void) const
{
	std::cout << "\033[31mShow Status" << std::endl;
	std::cout << "name   : " << this->get_name() << std::endl;
	std::cout << "hit    : " << this->get_hit() << std::endl;
	std::cout << "energy : " << this->get_energy() << std::endl;
	std::cout << "attack : " << this->get_attack() << std::endl;
	std::cout << "\33[m" << std::endl;
}

std::string	ClapTrap::get_name(void) const
{
	return (this->name_);
}

unsigned int	ClapTrap::get_attack(void) const
{
	return (this->attack_);
}

unsigned int	ClapTrap::get_hit(void) const
{
	return (this->hit_);
}

unsigned int	ClapTrap::get_energy(void) const
{
	return (this->energy_);
}

void	ClapTrap::set_name(std::string name)
{
	this->name_ = name;
}
void	ClapTrap::set_attack(unsigned int amount)
{
	this->attack_ = amount;
}
void	ClapTrap::set_hit(unsigned int amount)
{
	this->hit_ = amount;
}

void	ClapTrap::set_energy(unsigned int amount)
{
	this->energy_ = amount;
}
