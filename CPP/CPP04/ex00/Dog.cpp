/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:46 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 17:54:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(/* args */)
{
	type_ = "Dog";
	std::cout << "Dog: this is constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: this is destructor" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog: this is copy constructor" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog: this is copy assignment operator" << std::endl;
	if (this != &dog)
		this->type_ = dog.getType();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Waoooooooooooon" << std::endl;
}
