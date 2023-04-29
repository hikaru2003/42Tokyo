/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:04:43 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 13:23:00 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0, j = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[2][j] && argv[1][i] != argv[2][j])
				j++;
			if (argv[2][j] == '\0')
			{
				write(1, "0\n", 2);
				return (0);
			}
			i++;
			j++;
			if (argv[1][i] && argv[2][j] == '\0')
			{
				write(1, "0\n", 2);
				return (0);
			}
		}
		write(1, "1\n", 2);
		return (0);
	}
	write(1, "\n", 1);
	return (0);
}
