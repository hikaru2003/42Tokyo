/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:13:02 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 14:13:03 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact_[8];
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void set_phone_book(int id);
	void get_phone_book();
	void get_contact_information(int id);
};

#endif