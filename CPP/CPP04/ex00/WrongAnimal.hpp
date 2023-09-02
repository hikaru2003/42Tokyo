/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:09:55 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 13:10:56 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string	type_;

public:
	WrongAnimal(/* args */);
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &animal);
	WrongAnimal &operator=(const WrongAnimal &animal);

	std::string		getType() const;
	virtual void	makeSound() const;
};
