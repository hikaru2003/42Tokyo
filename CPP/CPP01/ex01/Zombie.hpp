/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:22 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 17:52:01 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name_;
public:
	inline Zombie();
	inline ~Zombie();
	void	announce( void );
	void	set_name(std::string name);
};

inline Zombie::Zombie()
{
	std::cout << name_ << ": this is constructor\n";
}

inline Zombie::~Zombie()
{
	std::cout << name_ << ": this is destructor\n";
}

Zombie*	zombieHorde( int N, std::string name_ );
