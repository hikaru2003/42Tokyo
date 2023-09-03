/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:30:46 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/03 17:39:17 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// constructor
Point::Point():x_(0), y_(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y):x_(x), y_(y)
{
	// std::cout << "Constructor that takes two float numbers called" << std::endl;
}

// destructor
Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

// copy constructor
Point::Point(const Point &point):x_(point.x_), y_(point.y_)
{
	// std::cout << "Copy constructor called" << std::endl;
}

// copy assignment operator
Point &Point::operator=(const Point &point)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &point)
	{
		const_cast<Fixed &>(x_) = point.get_x();
		const_cast<Fixed &>(y_) = point.get_y();
	}
	return (*this);
}

// method
const Fixed	&Point::get_x() const
{
	return this->x_;
}

const Fixed	&Point::get_y() const
{
	return this->y_;
}

float	Point::get_difference_x(const Point &p1, const Point &p2)
{
	return ((p1.x_ - p2.x_).toFloat());
}

float	Point::get_difference_y(const Point &p1, const Point &p2)
{
	return ((p1.y_ - p2.y_).toFloat());
}
