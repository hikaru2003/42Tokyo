/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:39:58 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/26 20:13:56 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flow(int sum, char c, int flag)
{
	if (INT_MAX / 10 < sum && c && flag == 0)
		return (1);
	if (sum == INT_MAX / 10 && INT_MAX % 10 < c - '0' && flag == 0)
		return (1);
	if (INT_MIN / 10 > -sum && c && flag == 1)
		return (-1);
	if (INT_MIN / 10 == -sum && INT_MIN % 10 > -(c - '0') && flag == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	flag;
	int	sum;

	flag = 0;
	sum = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = 1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		sum = sum * 10 + (*str - '0');
		str++;
		if (check_flow(sum, *str, flag) != 0)
			print_error();
	}
	if (*str != '\0')
		print_error();
	if (flag == 1)
		sum *= -1;
	return ((int)sum);
}
