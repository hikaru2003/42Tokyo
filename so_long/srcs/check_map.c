/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:34:45 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/16 16:18:52 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	top_bottom_check(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		if (data->map->row[x] != '1')
			print_error(data);
		x++;
	}
}

void	middle_check(t_data *data, int y)
{
	int	x;

	x = 0;
	while (x < data->width)
	{
		if (!ft_strchr("01CEP", data->map->row[x]))
			print_error(data);
		if ((x == 0 || x == data->width - 1) && data->map->row[x] != '1')
			print_error(data);
		if (data->map->row[x] == 'P')
		{
			if (data->player_x != 0)
				print_error(data);
			data->player_x = x;
			data->player_y = y;
		}
		if (data->map->row[x] == 'C')
			data->c_num++;
		x++;
	}
}

int	check_map(t_data *data)
{
	int	y;

	y = 0;
	data->map = data->head.next;
	while (y < data->height)
	{
		if (y == 0 || y == data->height - 1)
			top_bottom_check(data);
		else
			middle_check(data, y);
		y++;
		data->map = data->map->next;
	}
	check_goal(data);
	return (0);
}
