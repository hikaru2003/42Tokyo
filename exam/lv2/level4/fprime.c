/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:17:22 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/26 18:36:47 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	num;
	int	prime;

	prime = 2;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		while (1)
		{
			if (num <= 1)
			{
				printf("1");
				break ;
			}
			while (num % prime != 0)
				prime++;
			if (num == prime)
			{
				printf("%d\n", prime);
				return (0);
			}
			printf("%d*", prime);
			num /= prime;
		}
	}
	printf("\n");	
	return (0);
}