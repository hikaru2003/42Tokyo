/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:05:49 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 13:04:33 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain(/* args */);
	~Brain();
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);

	std::string	get_ideas(size_t i) const;
	void		set_ideas(size_t i, std::string str);
};
