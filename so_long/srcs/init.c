/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:33:08 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 14:50:29 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_init(t_data *data)
{
	data->space_img = mlx_xpm_file_to_image(data->mlx, "image/field.xpm", &(data->xpm_width), &(data->xpm_height));
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "image/stone.xpm", &(data->xpm_width), &(data->xpm_height));
	data->collect_img = mlx_xpm_file_to_image(data->mlx, "image/pikatyu.xpm", &(data->xpm_width), &(data->xpm_height));
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "image/myuu2.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_front_img = mlx_xpm_file_to_image(data->mlx, "image/player_front.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_back_img = mlx_xpm_file_to_image(data->mlx, "image/player_back.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_right_img = mlx_xpm_file_to_image(data->mlx, "image/player_right.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_left_img = mlx_xpm_file_to_image(data->mlx, "image/player_left.xpm", &(data->xpm_width), &(data->xpm_height));
	data->player_direction = FRONT;
	data->width = 0;
	data->height = 0;
	data->head.next = &data->head;
	data->head.prev = &data->head;
	data->player_x = 0;
	data->player_y = 0;
	data->c_num = 0;
	data->collected = 0;
	data->exit_flag = 0;
}