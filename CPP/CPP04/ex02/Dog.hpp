/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 15:51:50 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*dog_brain_;
public:
	Dog(/* args */);
	~Dog();
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);

	void	makeSound() const;
	std::string get_brain(size_t i) const;
	void	set_brain(size_t i, std::string str);
};
