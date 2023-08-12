/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:30:33 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/12 18:34:49 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Fixed
{
private:
	int fp_number_;
	static const int bits_;
	
public:
	Fixed(/* args */);
	Fixed(const Fixed &fixed); //コピーコンストラクタ
	Fixed &operator=(const Fixed &fixed); //コピー代入演算子
	~Fixed();
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};
