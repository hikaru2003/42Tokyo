/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:23:47 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/22 20:46:22 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
private:
	Fixed const	x_;
	Fixed const	y_;

public:
	// constructor
	Point();
	Point(const float x, const float y);

	// destructor
	~Point();

	// copy constructor
	Point(const Point &point);

	// copy assignment operator
	Point &operator=(const Point &point);

	// method
	static float	get_difference_x(const Point &p1, const Point &p2);
	static float	get_difference_y(const Point &p1, const Point &p2);
};
