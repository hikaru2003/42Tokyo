/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:41 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 17:54:00 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(/* args */)
{
	type_ = "Cat";
	std::cout << "Cat: this is constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: this is destructor" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat: this is copy constructor" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat: this is copy assignment operator" << std::endl;
	if (this != &cat)
		this->type_ = cat.getType();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Niamaaaaaaaaaao" << std::endl;
}