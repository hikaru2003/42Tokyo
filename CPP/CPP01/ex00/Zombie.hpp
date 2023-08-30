/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:22 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/30 20:26:11 by hmorisak         ###   ########.fr       */
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

Zombie*	newZombie( std::string name_ );
void	randomChump( std::string name_ );
