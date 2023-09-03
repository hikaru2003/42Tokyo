/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:07 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 13:26:59 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string	type_;

public:
	Animal(/* args */);
	virtual ~Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);

	std::string		getType() const;
	virtual void	makeSound() const = 0;
};
