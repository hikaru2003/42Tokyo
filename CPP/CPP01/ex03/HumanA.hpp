/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:26:41 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/30 20:27:15 by hmorisak         ###   ########.fr       */
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
