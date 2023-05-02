/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:19:16 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 12:38:21 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	to_base(char c, int str_base)
{
	int	i = 0;
	char	*s1 = "0123456789abcdef";
	char	*s2 = "0123456789ABCDEF";

	while (i < str_base)
	{
		if (c == s1[i] || c == s2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	num;
	int	minus;
	int	i;

	num = 0;
	minus = 1;
	i = 0;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i] && to_base(str[i], str_base) != -1)
	{
		num = num * str_base + to_base(str[i], str_base);
		i++;
	}
	num = num * minus;
	return (num);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char	*s = "-abc";
// 	int			str_base = 16;

// 	printf("%d\n", ft_atoi_base(s, str_base));
// 	printf("%d\n", 12 + 11 * 16 + 10 * 16 * 16);
// 	return (0);
// }
