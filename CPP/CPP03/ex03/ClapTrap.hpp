/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:59:07 by hmorisak          #+#    #+#             */
/*   Updated: 2023/09/04 21:03:53 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string		name_;
	unsigned int	hit_, energy_, attack_;
public:
	// constructor
	ClapTrap();
	ClapTrap(std::string name);
	
	// destructor
	virtual ~ClapTrap();
	
	// copy constructor
	ClapTrap(const ClapTrap &clap);

	// copy assignment operator
	ClapTrap &operator=(const ClapTrap &clap);
	
	// method
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void			get_status(void) const;
	virtual std::string		get_name(void) const;
	unsigned int	get_attack(void) const;
	unsigned int	get_hit(void) const;
	unsigned int	get_energy(void) const;

	void	set_name(std::string name);
	void	set_attack(unsigned int amount);
	void	set_hit(unsigned int amount);
	void	set_energy(unsigned int amount);
};
