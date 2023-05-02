/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:14:02 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 12:17:31 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i++;
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i++;
			if (argv[1][i])
				write(1, "   ", 3);
		}
	}
	write(1, "\n", 1);
	return (0);
}