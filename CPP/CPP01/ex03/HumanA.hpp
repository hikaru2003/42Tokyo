/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:26:41 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/06 15:30:16 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name_;
	Weapon		&weapon_;
public:
	inline HumanA(std::string name, Weapon &weapon);
	inline ~HumanA();
	void	attack();
};

HumanA::HumanA(std::string name, Weapon &weapon) :name_(name), weapon_(weapon)
{
}

HumanA::~HumanA()
{
}
