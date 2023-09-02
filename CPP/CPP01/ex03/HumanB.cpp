/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:34:12 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 13:59:01 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (weapon_ == NULL)
		std::cout << name_ << " attacks with their own hands" << std::endl;
	else
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}
