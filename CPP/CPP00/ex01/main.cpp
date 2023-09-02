/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:34:42 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/02 17:25:43 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	int			register_id = 0;
	int			required_id = 0;
	std::string	command;

	while (1)
	{
		std::cout << "enter ADD or SEARCH or EXIT\n";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "The program quits and the contacts are lose forever\n";
			return (0);
		}
		else if (command == "ADD")
		{
			if (register_id == 8)
				register_id = 0;
			phone_book.set_phone_book(register_id);
			register_id++;
		}
		else if (command == "SEARCH")
		{
			phone_book.get_phone_book();
			std::cout << "enter id\n";
			std::cin >> required_id;
			std::getline(std::cin, command);
			std::cout << "     index|  nickname|phone num.|darkest secret\n";
			phone_book.get_contact_information(required_id);
		}
		else if (command == "EXIT")
		{
			std::cout << "The program quits and the contacts are lose forever\n";
			return (0);
		}
		else
		{
			std::cout << command << "\n";
			std::cout << "Error\n";
		}
	}
}
