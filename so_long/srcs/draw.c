/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:53:22 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 14:52:57 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	data->map = data->head.next;
	while (i < data->height)
	{
		j = 0;
		x = 0;
		while (j < data->width)
		{
			if (data->map->row[j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->wall_img, x, y);
				x += data->xpm_width;
			}
			else if (data->map->row[j] == '0')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->space_img, x, y);
				x += data->xpm_width;
			}
			else if (data->map->row[j] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->collect_img, x, y);
				x += data->xpm_width;
			}
			else if (data->map->row[j] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->exit_img, x, y);
				x += data->xpm_width;
			}
			else if (data->map->row[j] == 'P')
			{
				if (data->player_direction == FRONT)
					mlx_put_image_to_window(data->mlx, data->win, data->player_front_img, x, y);
				if (data->player_direction == BACK)
					mlx_put_image_to_window(data->mlx, data->win, data->player_back_img, x, y);
				if (data->player_direction == RIGHT)
					mlx_put_image_to_window(data->mlx, data->win, data->player_right_img, x, y);
				if (data->player_direction == LEFT)
					mlx_put_image_to_window(data->mlx, data->win, data->player_left_img, x, y);
				x += data->xpm_width;
			}
			j++;
		}
		i++;
		y += data->xpm_height;
		data->map = data->map->next;
	}
	return (0);
}
