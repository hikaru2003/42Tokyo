/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:54:53 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 13:01:06 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*array;

	i = 0;
	if (end >= start)
	{
		array = (int *)malloc(sizeof(int) * (end - start + 1));
		if (!array)
			return (NULL);
		while (i <= end - start)
		{
			array[i] = end - i;
			i++;
		}
	}
	else
	{
		array = (int *)malloc(sizeof(int) * (start - end + 1));
		if (!array)
			return (NULL);
		while (i <= start - end)
		{
			array[i] = end + i;
			i++;
		}
	}
	return (array);
}

#include <stdio.h>
int	main(void)
{
	int	i = 0;
	int start = -1, end = -1;
	int	*array = ft_rrange(start, end);

	while (i < end - start + 1)
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("\n");
}
