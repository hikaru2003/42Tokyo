/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:09 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 13:13:48 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(/* args */)
{
	type_ = "Animal";
	std::cout << "Animal: this is constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: this is destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	*this = animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	if (this != &animal)
		this->type_ = animal.getType();
	return (*this);
}


std::string	WrongAnimal::getType() const
{
	return (type_);	
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal Sound" << std::endl;
}
