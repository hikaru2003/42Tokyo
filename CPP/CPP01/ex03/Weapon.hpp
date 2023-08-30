/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:24:16 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/30 17:59:05 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string type_;
public:
	inline Weapon(std::string type);
	inline ~Weapon();
	const std::string	&getType();
	void	setType(std::string type);
};

Weapon::Weapon(std::string type) : type_(type)
{
}

Weapon::~Weapon()
{
}
