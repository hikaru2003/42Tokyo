/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:12:30 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 14:12:31 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::set_phone_book(int id)
{
	contact_[id].set_contact();
}

void PhoneBook::get_phone_book()
{
	int id = 0;
	std::cout << "     index|first name| last name|  nickname\n";
	while (1)
	{
		if (contact_[id].is_empty() || id == 8)
			return ;
		contact_[id].get_contact(id);
		id++;
	}
}

void PhoneBook::get_contact_information(int id)
{
	if (id > 7)
	{
		std::cout << "id is out of range\n";
		return ;
	}
	if (contact_[id].is_empty())
	{
		std::cout << "id is out of range\n";
		return ;
	}
	contact_[id].get_information(id);
}