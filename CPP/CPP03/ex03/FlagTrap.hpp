/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:06:32 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 18:59:10 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap
{
protected:
	static const unsigned int	hit_ = 100;
	static const unsigned int	energy_ = 100;
	static const unsigned int	attack_ = 30;
public:
	// constructor
	FlagTrap();
	FlagTrap(std::string name);
	
	// destructor
	~FlagTrap();
	
	// copy constructor
	FlagTrap(const FlagTrap &flag);

	// copy assignment operator
	FlagTrap &operator=(const FlagTrap &flag);

	// method
	void	attack(const std::string &target);
	void	highFivesGuys(void);
	
};
