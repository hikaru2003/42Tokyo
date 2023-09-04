/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:06:18 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 18:07:04 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(/* args */)
{
	std::cout << "Brain: this is constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: this is destructor" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain: this is copy constructor" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain: this is copy assignment operator" << std::endl;
	if (this != &brain)
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = brain.get_ideas(i);
	return (*this);
}

std::string	Brain::get_ideas(size_t i) const
{
	if (i >= 100)
		return ("");
	return (this->ideas[i]);
}

void		Brain::set_ideas(size_t i, std::string str)
{
	if (i < 100)
		this->ideas[i] = str;
}
