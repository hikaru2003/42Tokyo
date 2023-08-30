/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:28:02 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/30 17:42:04 by hmorisak         ###   ########.fr       */
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
