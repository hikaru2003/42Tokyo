/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:03 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/04 17:56:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();


	delete(meta);
	delete(j);
	delete(i);

	// const WrongAnimal *meta1 = new WrongAnimal();
	// const WrongAnimal *k = new WrongCat();

	// std::cout <<meta1->getType() << " " << std::endl;
	// std::cout << k->getType() << " " << std::endl;
	// meta1->makeSound();
	// k->makeSound();

	// delete(meta1);
	// delete(k);
	
	return 0;
}
