/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:43 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 13:09:03 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat(/* args */);
	~Cat();
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);

	void	makeSound() const;
};

