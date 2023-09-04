/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:46 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 18:00:58 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(/* args */)
{
	try
	{
		type_ = "Dog";
		std::cout << "Dog: this is constructor" << std::endl;
		dog_brain_ = new Brain();
	}
	catch(const std::bad_alloc &e)
	{
		std::cerr << "bad_alloc" << e.what() << std::endl;
		std::exit(1);
	}
	
}

Dog::~Dog()
{
	delete dog_brain_;
	std::cout << "Dog: this is destructor" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog: this is copy constructor" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		std::cout << "Dog: this is copy assignment operator" << std::endl;
		this->type_ = dog.getType();
		this->dog_brain_ = dog.dog_brain_;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Waoooooooooooon" << std::endl;
}

std::string	Dog::get_brain(size_t i) const
{
	return (this->dog_brain_->get_ideas(i));
}

void	Dog::set_brain(size_t i, std::string str)
{
	this->dog_brain_->set_ideas(i, str);
}
