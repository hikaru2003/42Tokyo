/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:59:07 by hmorisak          #+#    #+#             */
/*   Updated: 2023/08/18 18:55:42 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string		name_;
	unsigned int	hit_, energy_, attack_;
public:
	// constructor
	ClapTrap();
	ClapTrap(std::string name);
	
	// destructor
	~ClapTrap();
	
	// copy constructor
	ClapTrap(const ClapTrap &clap);

	// copy assignment operator
	ClapTrap &operator=(const ClapTrap &clap);
	
	// method
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void			get_status(void);
	unsigned int	get_attack(void);
	unsigned int	get_hit(void);
	unsigned int	get_energy(void);

	void	set_attack(unsigned int amount);
};
