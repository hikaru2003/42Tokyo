/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:09 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/26 13:14:11 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(/* args */)
{
	type_ = "Animal";
}

Animal::~Animal()
{
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this != &animal)
		this->type_ = animal.get_type();
	return (*this);
}


std::string	Animal::get_type() const
{
	return (type_);	
}

void	Animal::makeSound() const
{
	std::cout << "Animaaaaaaaaaal" << std::endl;
}
