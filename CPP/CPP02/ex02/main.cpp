/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:30:14 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 17:28:14 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;


	// Fixed const c( 10 );
	// Fixed const d( 42.42f );

	// std::cout << "c is " << c.toFloat() << std::endl;
	// std::cout << "d is " << d.toFloat() << std::endl;

	// std::cout << "c + d = " << (c + d) << std::endl;
	// std::cout << "c - d = " << (c - d) << std::endl;
	// std::cout << "c * d = " << (c * d) << std::endl;
	// std::cout << "c / d = " << (c / d) << std::endl;

	// std::cout << "1: true, 0: false" << std::endl;
	// std::cout << "c < d -> " << (c < d) << std::endl;
	// std::cout << "c <= d -> " << (c <= d) << std::endl;
	// std::cout << "c > d -> " << (c > d) << std::endl;
	// std::cout << "c >= d -> " << (c >= d) << std::endl;
	// std::cout << "c == d -> " << (c == d) << std::endl;
	// std::cout << "c != d -> " << (c != d) << std::endl;
	
	return 0;
}