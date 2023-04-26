/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:38:20 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/26 18:58:29 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		digit;
	int		tmp;
	char	*num;

	digit = 0;
	tmp = nbr;
	if (nbr <= 0)
	{
		digit++;
		tmp *= -1;
	}
	while (tmp != 0)
	{
		tmp /= 10;
		digit++;
	}
	num = (char *)malloc(digit + 1);
	if (!num)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		num[0] = '-';
	}
	num[digit] = '\0';
	while (nbr > 9)
	{
		num[--digit] = nbr % 10 + '0';
		nbr /= 10;
	}
	num[--digit] = nbr + '0';
	return (num);
}

#include <stdio.h>
int	main(void)
{
	int	i = 0;
	printf("%s\n", ft_itoa(i));
	return (0);
}