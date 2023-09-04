/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:41 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 18:00:23 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(/* args */)
{
	try
	{
		std::cout << "Cat: this is constructor" << std::endl;
		type_ = "Cat";
		cat_brain_ = new Brain();
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << "bad_alloc" << e.what() << std::endl;
		std::exit(1);
	}
}

Cat::~Cat()
{
	delete cat_brain_;
	std::cout << "Cat: this is destructor" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat: this is copy constructor" << std::endl;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		std::cout << "Cat: this is copy assignment operator" << std::endl;
		this->type_ = cat.getType();
		this->cat_brain_ = cat.cat_brain_;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Niamaaaaaaaaaao" << std::endl;
}

std::string	Cat::get_brain(size_t i) const
{
	return (this->cat_brain_->get_ideas(i));
}

void	Cat::set_brain(size_t i, std::string str)
{
	this->cat_brain_->set_ideas(i, str);
}
