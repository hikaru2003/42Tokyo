/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:41:57 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/30 20:28:41 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType()
{
	return (type_);
}

void	Weapon::setType(std::string type)
{
	type_ = type;
}
