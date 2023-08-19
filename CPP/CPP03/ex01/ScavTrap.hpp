/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/18 18:54:47 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	// constructor
	ScavTrap();
	ScavTrap(std::string name);
	
	// destructor
	~ScavTrap();
	
	// copy constructor
	ScavTrap(const ScavTrap &scav);

	// copy assignment operator
	ScavTrap &operator=(const ScavTrap &scav);

	// method
	void	attack(const std::string &target);
	void	guardGate(void);
	
};
