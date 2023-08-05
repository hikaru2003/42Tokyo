/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:22 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 17:50:29 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <new>

class Zombie
{
private:
	std::string name_;
public:
	inline Zombie( std::string s );
	inline ~Zombie();
	void	announce( void );
};

inline Zombie::Zombie( std::string s )
{
	name_ = s;
	std::cout << name_ << ": this is constructor\n";
}

inline Zombie::~Zombie()
{
	std::cout << name_ << ": this is destructor\n";
}

Zombie*	newZombie( std::string name_ );
void	randomChump( std::string name_ );
