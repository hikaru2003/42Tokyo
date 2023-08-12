/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:01:20 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/12 14:16:19 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "please input a parameter" << std::endl;
		return (1);
	}
	
	harl.complain(std::string(argv[1]));
	return (0);
}