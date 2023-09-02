/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:53 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 13:11:40 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	type_ = "WrongAnimal";
	std::cout << "WrongAnimal: this is constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: this is destructor" << std::endl;
}

WrongAnimal(const WrongAnimal &animal);
WrongAnimal &operator=(const WrongAnimal &animal);

std::string		getType() const;
virtual void	makeSound() const;