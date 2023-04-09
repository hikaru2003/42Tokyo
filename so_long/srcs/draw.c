/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:53:22 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/09 14:37:23 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int height;
	int width;

	i = 0;
	y = 0;
	while (i < data->height)
	{
		j = 0;
		x = 0;
		while (j < data->width)
		{
			if (data->map->row[j] == '1')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, "image/voldemort.xpm", &width, &height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
				x += width;
			}
			else if (data->map->row[j] == '0')
			{
				data->img = mlx_new_image(data->mlx, width, height);
				// img.img = mlx_xpm_file_to_image(mlx, "image/tile.xpm", &width, &height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
				x += width;
			}
			else if (data->map->row[j] == 'C')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, "image/dobby.xpm", &width, &height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
				x += width;
			}
			else if (data->map->row[j] == 'E')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, "image/dumbledore.xpm", &width, &height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
				x += width;
			}
			else if (data->map->row[j] == 'P')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, "image/sirius.xpm", &width, &height);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
				x += width;
			}
			j++;
		}
		i++;
		y += height;
		data->map = data->map->next;
	}
	return (0);
}
