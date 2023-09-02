/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:24:16 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 11:42:39 by hmorisak         ###   ########.fr       */
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
	Weapon(std::string type);
	~Weapon();
	const std::string	&getType();
	void	setType(std::string type);
};
