/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:13 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 21:04:11 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap, public FlagTrap
{
private:
	std::string	name_;

public:
	// constructor
	DiamondTrap(/* args */);
	DiamondTrap(std::string name);

	// destructor
	~DiamondTrap();

	// copy constructor
	DiamondTrap(const DiamondTrap &diamond);

	// copy assignment operator
	DiamondTrap &operator=(const DiamondTrap &diamond);

	// method
	virtual std::string		get_name(void) const;
	void	attack(const std::string &target);
	void	whoAmI(void);
};
