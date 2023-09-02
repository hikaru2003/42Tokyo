/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:19 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 11:45:51 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string s )
{
	name_ = s;
	std::cout << name_ << ": this is constructor\n";
}

Zombie::~Zombie()
{
	std::cout << name_ << ": this is destructor\n";
}

void	Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}

