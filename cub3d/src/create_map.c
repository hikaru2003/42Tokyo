/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:38:58 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/11 15:38:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	create_map(t_data *data, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof(char *) * data->max_y);
	if (!data->map)
		print_error("bad_alloc");
	while (i < data->max_y)
	{
		data->map[i] = (char *)malloc(sizeof(char) * (data->max_x + 1));
		if (!data->map[i])
			print_error("bad_alloc");
		int j = 0;
		while (j < data->max_x)
		{
			data->map[i][j] = ' ';
			j++;
		}
		data->map[i][j] = '\0';
		i++;
	}
	i = 0;
	while (i < 8)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	i = 0;
	while (i < data->max_y)
	{
		line = get_next_line(fd);
		int j = 0;
		while (line[j] != '\n' && line[j] != '\0')
		{
			data->map[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
	close (fd);
}