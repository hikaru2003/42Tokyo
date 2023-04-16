/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:56:03 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/16 19:56:04 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_up(t_data *data, t_map_direct **index)
{
	index[data->player_y][data->player_x].up = 1;
	if (data->map->prev->row[data->player_x] != '1')
	{
		if (data->map->prev->row[data->player_x] == 'C')
			data->collected++;
		if (data->map->prev->row[data->player_x] == 'E')
		{
			data->exit_flag = 1;
			if (data->collected == data->c_num)
				return (1);
		}
		else
		{
			current_pos_img(data);
			data->map->prev->row[data->player_x] = 'P';
		}
		data->player_y -= 1;
	}
	return (0);
}

int	go_down(t_data *data, t_map_direct **index)
{
	index[data->player_y][data->player_x].down = 1;
	if (data->map->next->row[data->player_x] != '1')
	{
		if (data->map->next->row[data->player_x] == 'C')
			data->collected++;
		if (data->map->next->row[data->player_x] == 'E')
		{
			data->exit_flag = 1;
			if (data->collected == data->c_num)
				return (1);
		}
		else
		{
			current_pos_img(data);
			data->map->next->row[data->player_x] = 'P';
		}
		data->player_y += 1;
	}
	return (0);
}

int	go_right(t_data *data, t_map_direct **index)
{
	index[data->player_y][data->player_x].right = 1;
	if (data->map->row[data->player_x + 1] != '1')
	{
		if (data->map->row[data->player_x + 1] == 'C')
			data->collected++;
		if (data->map->row[data->player_x + 1] == 'E')
		{
			data->exit_flag = 1;
			if (data->collected == data->c_num)
				return (1);
		}
		else
		{
			current_pos_img(data);
			data->map->row[data->player_x + 1] = 'P';
		}
		data->player_x += 1;
	}
	return (0);
}

int	go_left(t_data *data, t_map_direct **index)
{
	index[data->player_y][data->player_x].left = 1;
	if (data->map->row[data->player_x - 1] != '1')
	{
		if (data->map->row[data->player_x - 1] == 'C')
			data->collected++;
		if (data->map->row[data->player_x - 1] == 'E')
		{
			data->exit_flag = 1;
			if (data->collected == data->c_num)
				return (1);
		}
		else
		{
			current_pos_img(data);
			data->map->row[data->player_x - 1] = 'P';
		}
		data->player_x -= 1;
	}
	return (0);
}
