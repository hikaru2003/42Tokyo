/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:34:45 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/29 21:59:12 by hmorisak         ###   ########.fr       */
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
	t_map	head;
	t_map	*map;

	data->height = 0;
	head.next = &head;
	head.prev = &head;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = (t_map *)malloc(sizeof(t_map));
		if (!map)
			return (head);
		map->row = line;
		insert(&head, map);
		data->height++;
	}
	return (head);
}

int	check_map(int fd, t_data *data)
{
	t_map	head;
	t_map	*map;
	int		i;
	int		index;

	i = 0;
	head = creat_map(fd, data);
	map = head.next;
	while (i < data->height)
	{
		index = 0;
		if (i == 0 || i == data->height - 1)
		{
			while (index < data->width)
			{
				if (map->row[index] != '1')
					print_error();
				index++;
			}
		}
		else
		{
			while (index < data->width)
			{
				if (index == 0 || index == data->width - 1)
				{
					if (map->row[index] != '1')
						print_error();
				}
				else
				{
					if (!ft_strchr("0CEP", map->row[index]))
						print_error();
				}
				index++;
			}	
		}
		i++;
		map = map->next;
	}
	return (0);
}
