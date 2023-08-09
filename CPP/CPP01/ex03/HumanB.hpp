/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:28:02 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/09 17:24:48 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name_;
	Weapon		*weapon_;
public:
	inline HumanB(std::string name);
	inline ~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
};

HumanB::HumanB(std::string name) : name_(name)
{
}

HumanB::~HumanB()
{
}
