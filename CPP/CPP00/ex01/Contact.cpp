/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:12:14 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/29 19:15:36 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

void Contact::set_contact()
{
	do{
		std::cout << "enter first name\n";
		std::getline(std::cin, first_name_);
		// if (std::cin.eof())
		// 	return ;
	} while (!std::cin.eof() && first_name_.empty());
	do{
		std::cout << "enter last name\n";
		std::getline(std::cin, last_name_);
	} while (!std::cin.eof() && last_name_.empty());
	do{
		std::cout << "enter nickname\n";
		std::getline(std::cin, nickname_);
	} while (!std::cin.eof() && nickname_.empty());
	do{
		std::cout << "enter phone number\n";
		std::getline(std::cin, phone_number_);
	} while (!std::cin.eof() && phone_number_.empty());
	do{
		std::cout << "enter darkest secret\n";
		std::getline(std::cin, darkest_secret_);
	} while (!std::cin.eof() && darkest_secret_.empty());
}

void Contact::get_contact(int id)
{
	std::cout << "         " << id << "|";
	std::cout << get_display_letter(first_name_) << "|";
	std::cout << get_display_letter(last_name_)  << "|";
	std::cout << get_display_letter(nickname_) << "\n";
}

std::string Contact::get_display_letter(std::string original_letter)
{
	int str_len = 0;
	std::string display_letter;

	str_len = original_letter.length();
	display_letter = original_letter;
	for (int i = 0; i < 10 - str_len; i++)
		display_letter = " " + display_letter;
	if (str_len > 10)
		display_letter = original_letter.substr(0, 9) + ".";
	return (display_letter);
}

bool Contact::is_empty()
{
	if (first_name_.empty())
		return (true);
	return (false);
}

void Contact::get_information(int id)
{
	std::cout << "         " << id << "|";
	std::cout << get_display_letter(nickname_) << "|";
	std::cout << get_display_letter(phone_number_)  << "|";
	std::cout << get_display_letter(darkest_secret_) << "\n";
}