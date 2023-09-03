/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:37:03 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 16:02:12 by hikaru           ###   ########.fr       */
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
	
	// Cat *cat = new Cat();
	// Dog *dog = new Dog();
	
	// animal[0] = cat;
	// animal[1] = new Cat();
	// animal[2] = dog;
	// animal[3] = new Dog();
	
	for (size_t i = 0; i < 4; i++)
		delete animal[i];

	// Dog *dog = new Dog();
	// std::cout << "type = " << dog->getType() << std::endl;
	// dog->set_brain(1, "hikaru");
	// dog->set_brain(2, "morisaki");
	// dog->set_brain(3, "hello");
	// dog->set_brain(3, "world");
	
	// for (size_t i = 0; i < 5; i++)
	// 	std::cout << i << ": " << dog->get_brain(i) << std::endl;
	// delete dog;

	return 0;
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q ex01");
// }