/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:59 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 11:55:32 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
	type_ = "Wrong Cat";
	std::cout << "Wrong Cat: this is constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat: this is destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat)
{
	*this = cat;
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	if (this != &cat)
		this->type_ = cat.getType();
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Niaoooooo" << std::endl;
}