/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:22 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/30 20:26:51 by hmorisak         ###   ########.fr       */
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

Zombie*	zombieHorde( int N, std::string name_ );
