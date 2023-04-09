/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:34:45 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/09 20:59:14 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert(t_map *head, t_map *new)
{
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	new->next = head;
}

t_map	creat_map(int fd, t_data *data)
{
	char	*line;
	// t_map	head;
	t_map	*map;

	data->height = 0;
	// head.next = &head;
	// head.prev = &head;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = (t_map *)malloc(sizeof(t_map));
		if (!map)
			return (data->head);
		map->row = line;
		insert(&data->head, map);
		data->height++;
	}
	// data->width = ft_strlen(data->head.next->row) - 1;
	return (data->head);
}

int	check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->map = data->head.next;
	data->width = ft_strlen(data->map->row) - 1;
	while (y < data->height)
	{
		x = 0;
		if (y == 0 || y == data->height - 1)
		{
			while (x < data->width)
			{
				if (data->map->row[x] != '1')
					print_error();
				x++;
			}
		}
		else
		{
			while (x < data->width)
			{
				if (x == 0 || x == data->width - 1)
				{
					if (data->map->row[x] != '1')
						print_error();
				}
				else
				{
					if (data->map->row[x] == 'P')
					{
						data->player_x = x;
						data->player_y = y;
					}
					if (data->map->row[x] == 'C')
					{
						data->c_num++;
					}
					if (!ft_strchr("01CEP", data->map->row[x]))
						print_error();
				}
				x++;
			}
		}
		y++;
		data->map = data->map->next;
	}
	return (0);
}
