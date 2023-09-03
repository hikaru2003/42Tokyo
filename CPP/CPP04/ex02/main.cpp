/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:03 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 16:08:00 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal	*animal[4];

	animal[0] = new Cat();
	animal[1] = new Cat();
	animal[2] = new Dog();
	animal[3] = new Dog();

	// animal[0]->makeSound();
	// animal[0]->Animal::makeSound();
	// animal[2]->makeSound();
	// animal[2]->Animal::makeSound();
	
	for (size_t i = 0; i < 4; i++)
		delete animal[i];
	return 0;
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q ex02");
// }