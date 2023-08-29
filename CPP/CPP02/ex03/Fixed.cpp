/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:30:35 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/26 13:09:03 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructor
Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	fp_number_ = 0;
}

Fixed::Fixed(const int param)
{
	// std::cout << "Int constructor called" << std::endl;
	fp_number_ = param * 256;
}

Fixed::Fixed(const float param)
{
	// std::cout << "Float constructor called" << std::endl;
	fp_number_ = roundf(param * 256);
}

// copy constructor
Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

// copy assignment operator
Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fp_number_ = fixed.getRawBits();
	return (*this);
}

// destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// method
int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_number_);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->fp_number_ = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)fp_number_ / 256);
}

int		Fixed::toInt(void) const
{
	return (fp_number_ / 256);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->fp_number_ > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->fp_number_ < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->fp_number_ >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->fp_number_ <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->fp_number_ == rhs.getRawBits());	
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->fp_number_ != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++()
{
	++fp_number_;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++fp_number_;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	--fp_number_;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--fp_number_;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs.fp_number_ < rhs.fp_number_ ? lhs : rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs.fp_number_ < rhs.fp_number_ ? lhs : rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs.fp_number_ > rhs.fp_number_ ? lhs : rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs.fp_number_ > rhs.fp_number_ ? lhs : rhs);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}