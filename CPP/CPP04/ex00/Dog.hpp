/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:48 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 13:09:19 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(/* args */);
	~Dog();
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);

	void	makeSound() const;
};
