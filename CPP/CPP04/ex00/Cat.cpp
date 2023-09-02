/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:41 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 12:55:09 by hikaru           ###   ########.fr       */
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
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
		this->type_ = cat.getType();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Niamaaaaaaaaaao" << std::endl;
}