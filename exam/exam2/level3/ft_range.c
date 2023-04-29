/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:43:18 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 12:59:51 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
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
			array[i] = start + i;
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
			array[i] = start - i;
			i++;
		}
	}
	return (array);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i = 0;
// 	int start = -1, end = -4;
// 	int	*array = ft_range(start, end);

// 	while (i < start - end + 1)
// 	{
// 		printf("%d, ", array[i]);
// 		i++;
// 	}
// 	printf("\n");
// }
