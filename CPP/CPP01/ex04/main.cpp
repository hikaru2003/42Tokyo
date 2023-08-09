/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:27:49 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/09 20:13:02 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "please input three parameters" << std::endl;
		return (0);
	}

	std::string data;
	{
		std::ifstream ifs(argv[1]);
		if (!ifs)
		{
			std::cout << "cannot open file" << std::endl;
			return (0);
		}
		std::ofstream ofs(std::string(argv[1]) + ".replace");
		if (!ofs)
		{
			std::cout << "cannot create file" << std::endl;
			return (0);
		}
		
		std::string	buf;
		int	pos, convert_string_length = strlen(argv[2]);
		while (1)
		{
			std::getline(ifs, buf);
			pos = 0;
			while (1)
			{
				pos = buf.find(argv[2], pos);
				if (pos == std::string::npos)
					break ;
				buf.erase(pos, convert_string_length);
				buf.insert(pos, argv[3]);
				pos++;
			}
			if (ifs.eof())
			{
				data += buf;
				break ;
			}
			data += buf + "\n";
		}
		ofs << data;
	}

	return (0);
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q sed");
// }