/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:01:19 by hikaru            #+#    #+#             */
/*   Updated: 2023/09/10 19:31:22 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	next_frame(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		// ft_destroy(data)と同じ内容？
		mlx_destroy_window(data->mlx, data->win);
		// free data, etc...
		exit (0);
	}
	if (keycode == UP_ARROW || keycode == KEY_W)
	// go front
	if (keycode == DOWN_ARROW || keycode == KEY_S)
	// go back
	if (keycode == KEY_A)
	// go left
	if (keycode == KEY_D)
	// go right
	if (keycode == LEFT_ARROW)
	// turn left
	if (keycode == RIGHT_ARROW)
	// turn right

	return (0);
}
