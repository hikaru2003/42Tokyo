/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:19 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/30 20:27:00 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

inline Zombie::Zombie()
{
	std::cout << name_ << ": this is constructor\n";
}

inline Zombie::~Zombie()
{
	std::cout << name_ << ": this is destructor\n";
}

void	Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string name)
{
	name_ = name;
}