/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:43 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 15:51:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*cat_brain_;
public:
	Cat(/* args */);
	~Cat();
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);

	void	makeSound() const;
	std::string get_brain(size_t i) const;
	void	set_brain(size_t i, std::string str);
};
