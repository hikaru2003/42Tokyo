/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:24:16 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 20:40:00 by hikaru           ###   ########.fr       */
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
	std::string	getType();
	void	setType(std::string type);
};

Weapon::Weapon(std::string type)
{
	type_ = type;
}

Weapon::~Weapon()
{
}
