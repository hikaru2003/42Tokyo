/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:30:33 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/16 21:34:19 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int fp_number_;
	static const int bits_ = 8;
	
public:
	// constructor
	Fixed();
	Fixed(const int param);
	Fixed(const float param);
	
	// destructor
	~Fixed();
	
	// copy constructor
	Fixed(const Fixed &fixed);
	
	// copy assignment operator
	Fixed &operator=(const Fixed &fixed);
	
	// method
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
	// overload
	// rhs:right hand side, lhs:left hand side
	bool	operator>(Fixed &rhs);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
