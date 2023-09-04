/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:09 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 17:53:26 by hikaru           ###   ########.fr       */
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

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal: this is copy constructor" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal: this is copy assignment operator" << std::endl;
	if (this != &animal)
		this->type_ = animal.getType();
	return (*this);
}


std::string	Animal::getType() const
{
	return (type_);	
}

void	Animal::makeSound() const
{
	std::cout << "Animaaaaaaaaaal" << std::endl;
}
