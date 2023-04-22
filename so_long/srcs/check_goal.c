/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_goal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:34 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/22 13:21:03 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_to_structure(t_data *data)
{
	char	**array;
	int		y;

	y = 0;
	array = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!array)
		print_error(data);
	data->map = data->head.next;
	while (y < data->height)
	{
		array[y] = ft_strdup(data->map->row);
		y++;
		data->map = data->map->next;
	}
	array[y] = NULL;
	return (array);
}

void	update_map_status(t_map_status **map, t_data *data, int player_x, int player_y)
{
	if (data->array[player_y][player_x] == '1')
		return ;
	if (player_x <= 0 || player_x >= data->width - 1 || player_y <= 0
		|| player_y >= data->height - 1)
		return ;
	map[player_y][player_x].status = 1;
	if (map[player_y][player_x].up == 0)
	{
		map[player_y][player_x].up = 1;
		update_map_status(map, data, player_x, player_y - 1);
	}
	if (map[player_y][player_x].down == 0)
	{
		map[player_y][player_x].down = 1;
		update_map_status(map, data, player_x, player_y + 1);
	}
	if (map[player_y][player_x].right == 0)
	{
		map[player_y][player_x].right = 1;
		update_map_status(map, data, player_x + 1, player_y);
	}
	if (map[player_y][player_x].left == 0)
	{
		map[player_y][player_x].left = 1;
		update_map_status(map, data, player_x - 1, player_y);
	}
}

void	check_map_status(t_map_status **map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->map = data->head.next;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (map[y][x].status == 0 &&
			(data->map->row[x] == 'C' || data->map->row[x] == 'E'))
				print_error(data);
			x++;
		}
		y++;
		data->map = data->map->next;
	}
}

int	check_goal(t_data *data)
{
	t_map_status	**map;

	data->array = map_to_structure(data);
	map = (t_map_status **)malloc(sizeof(t_map_status *) * data->height);
	if (!map)
		print_error(data);
	map_status_init(map, data);
	update_map_status(map, data, data->player_x, data->player_y);
	check_map_status(map, data);
	array_free(data);
	return (1);
}
