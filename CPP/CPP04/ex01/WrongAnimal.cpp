/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:53 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 17:54:50 by hikaru           ###   ########.fr       */
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

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << "WrongAnimal: this is copy constructor" << std::endl;
	*this = animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	std::cout << "WrongAnimal: this is copy assignment operator" << std::endl;
	if (this != &animal)
		this->type_ = animal.getType();
	return (*this);
}

std::string		WrongAnimal::getType() const
{
	return (type_);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrooooooooooong" << std::endl;
}
