/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:12:56 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/05 14:12:57 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>

class Contact
{
private:
	std::string first_name_, last_name_, phone_number_, nickname_, darkest_secret_;
public:
	Contact(/* args */);
	~Contact();
	void set_contact();
	void get_contact(int id);
	std::string get_display_letter(std::string original_letter);
	bool is_empty();
	void get_information(int id);
};

#endif