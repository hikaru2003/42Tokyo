/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:07 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/26 13:14:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string	type_;

public:
	Animal(/* args */);
	~Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);

	void	get_type() const;
	void	makeSound() const;
};
