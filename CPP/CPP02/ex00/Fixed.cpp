/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:30:35 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/12 19:36:41 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(/* args */)
{
	std::cout << "Default constructor called" << std::endl;
	fp_number_ = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp_number_ = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fp_number_ = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fp_number_;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_number_ = raw;
}
