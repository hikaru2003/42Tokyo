/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:24:23 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/22 21:20:58 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 外積をとる
float	sign(Point const p1, Point const p2, Point const p3)
{
	return (Point::get_difference_x(p1, p3) * Point::get_difference_y(p2, p3) - Point::get_difference_x(p2, p3) * Point::get_difference_y(p1, p3));
}

// 外積の正負が一致するなら内点である
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	b1, b2, b3;

	b1 = sign(point, a, b) < 0.0f;
	b2 = sign(point, b, c) < 0.0f;
	b3 = sign(point, c, a) < 0.0f;

	return ((b1 == b2) && (b2 == b3));
}
