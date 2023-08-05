/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:19 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 17:49:52 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string name)
{
	name_ = name;
}