/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_goal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:34 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/16 19:37:36 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	updata_map_status(int **map_status, t_data *data)
// {
// 	if (data->player_x <= 0 || data->player_x >= data->width - 1 || data->player_y <= 0 || data->player_y >= data->height - 1)
// 		return ;
// 	// printf("left=%c, right=%c\n", data->map->row[data->player_x - 1], data->map->row[data->player_x + 1]);
// 	map_status[data->player_y][data->player_x] = 1;
// 	// if (map_status[data->player_y - 1][data->player_x] != 1 && data->map->prev->row[data->player_x] != '1')
// 	if (data->map->prev->row[data->player_x] != '1')
// 	{
// 		map_status[data->player_y - 1][data->player_x] = 1;
// 		data->map = data->map->prev;
// 		data->player_y -= 1;
// 		if (data->player_y != 0)
// 			updata_map_status(map_status, data);
// 	}
// 	// if (map_status[data->player_y + 1][data->player_x] != 1 && data->map->next->row[data->player_x] != '1')
// 	if (data->map->next->row[data->player_x] != '1')
// 	{
// 		map_status[data->player_y + 1][data->player_x] = 1;
// 		data->map = data->map->next;
// 		data->player_y += 1;
// 		if (data->player_y != data->height - 1)
// 			updata_map_status(map_status, data);
// 	}
// 	// if (map_status[data->player_y][data->player_x - 1] != 1 && data->map->row[data->player_x - 1] != '1')
// 	if (data->player_x != 0 && data->map->row[data->player_x - 1] != '1')
// 	{
// 		printf("left not 1\n");
// 		map_status[data->player_y][data->player_x - 1] = 1;
// 		data->player_x -= 1;
// 		if (data->player_x != 0)
// 			updata_map_status(map_status, data);
// 	}
// 	// if (map_status[data->player_y][data->player_x + 1] != 1 && data->map->row[data->player_x + 1] != '1')
// 	if (data->player_x != data->width - 1 && data->map->row[data->player_x + 1] != '1')
// 	{
// 		printf("right not 1\n");
// 		map_status[data->player_y][data->player_x + 1] = 1;
// 		data->player_x += 1;
// 		if (data->player_x != data->width - 1)
// 			updata_map_status(map_status, data);
// 	}
// }

// void	check_map_status(int **map_status, t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	data->map = data->head.next;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		while (x < data->width)
// 		{
// 			if (map_status[y][x] == 0 && (data->map->row[x] == 'C' || data->map->row[x] == 'E'))
// 				print_error(data);
// 			x++;
// 		}
// 		y++;
// 		data->map = data->map->next;
// 	}
// }

// int	check_goal(t_data *data)
// {
// 	int	**map_status;

// 	map_status = (int **)malloc(sizeof(int *) * data->height);
// 	if (!map_status)
// 		print_error(data);
// 	map_status_init(map_status, data);
// 	move_to_player_y(data);
// 	if (data->map->row[data->player_x] != 'P')
// 		serch_all(data);
// 	updata_map_status(map_status, data);
// 	check_map_status(map_status, data);
// 	return (1);
// }

void	map_status_init(t_map_status **map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		map[y] = (t_map_status *)malloc(sizeof(t_map_status) * data->width);
		if (!map[y])
			print_error(data);
		while (x < data->width)
		{
			map[y][x].status = 0;
			map[y][x].up = 0;
			map[y][x].down = 0;
			map[y][x].right = 0;
			map[y][x].left = 0;
			x++;
		}
		y++;
	}
}

void	updata_map_status(t_map_status **map, t_data *data)
{
	if (data->player_x <= 0 || data->player_x >= data->width - 1 || data->player_y <= 0 || data->player_y >= data->height - 1)
		return ;
	map[data->player_y][data->player_x].status = 1;
	if (map[data->player_y][data->player_x].up == 0)
	{
		map[data->player_y][data->player_x].up = 1;
		map[data->player_y - 1][data->player_x].down = 1;
		if (data->map->prev->row[data->player_x] != '1')
		{
			map[data->player_y - 1][data->player_x].status = 1;
			data->player_y -= 1;
			data->map = data->map->prev;
			updata_map_status(map, data);
		}
	}
	if (map[data->player_y][data->player_x].down == 0)
	{
		map[data->player_y][data->player_x].down = 1;
		map[data->player_y + 1][data->player_x].up = 1;
		if (data->map->next->row[data->player_x] != '1')
		{
			map[data->player_y + 1][data->player_x].status = 1;
			data->player_y += 1;
			data->map = data->map->next;
			updata_map_status(map, data);
		}
	}
	if (map[data->player_y][data->player_x].right == 0)
	{
		map[data->player_y][data->player_x].right = 1;
		map[data->player_y][data->player_x + 1].left = 1;
		if (data->map->row[data->player_x + 1] != '1')
		{
			map[data->player_y][data->player_x + 1].status = 1;
			data->player_x += 1;
			updata_map_status(map, data);
		}
	}
	if (map[data->player_y][data->player_x].left == 0)
	{
		map[data->player_y][data->player_x].left = 1;
		map[data->player_y][data->player_x - 1].right = 1;
		if (data->map->row[data->player_x - 1] != '1')
		{
			map[data->player_y][data->player_x - 1].status = 1;
			data->player_x -= 1;
			updata_map_status(map, data);
		}
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
			if (map[y][x].status == 0 && (data->map->row[x] == 'C' || data->map->row[x] == 'E'))
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

	map = (t_map_status **)malloc(sizeof(t_map_status *) * data->height);
	if (!map)
		print_error(data);
	map_status_init(map, data);
	move_to_player_y(data);
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	updata_map_status(map, data);
	int x = 0, y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			printf("%d", map[y][x].status);
			x++;
		}
		printf("\n");
		y++;
	}
	check_map_status(map, data);
	return (1);
}
