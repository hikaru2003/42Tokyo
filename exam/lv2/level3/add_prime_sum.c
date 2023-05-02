/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:35:36 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 11:56:51 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_prime(int prime)
{
	int	tmp;

	tmp = 2;
	while (tmp < prime)
	{
		if (prime % tmp == 0)
			return (1);
		tmp++;
	}
	return (0);
}

void	ft_putnbr(int n)
{
	int	syou;
	int	amari;
	char	s;

	syou = n / 10;
	amari = n % 10;
	if (syou != 0)
		ft_putnbr(syou);
	s = amari + '0';
	write(1, &s, 1);
}

int	main(int argc, char **argv)
{
	int	prime;
	int	num;
	int	sum;

	prime = 2;
	num = 0;
	sum = 0;
	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num < prime)
			write(1, "1", 1);
		else
		{
			while (prime <= num)
			{
				if (is_prime(prime) == 0)
					sum += prime;
				prime++;
			}
			ft_putnbr(sum);
		}
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
