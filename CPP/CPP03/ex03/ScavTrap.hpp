/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 18:59:00 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	static const unsigned int	hit_ = 100;
	static const unsigned int	energy_ = 50;
	static const unsigned int	attack_ = 20;
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
