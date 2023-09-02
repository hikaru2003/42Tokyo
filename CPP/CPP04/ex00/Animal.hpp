/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:07 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 12:56:24 by hikaru           ###   ########.fr       */
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
	~Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);

	std::string		getType() const;
	virtual void	makeSound() const;
};
