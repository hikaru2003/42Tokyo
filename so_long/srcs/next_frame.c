/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:41:42 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/05 19:14:57 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_step(t_data *data)
{
	mlx_hook(vars.win, 2, 1, next_frame, &data);
}

int	next_frame(int keycode, t_data *data)
{
	if (keycode == 87 || keycode == 38)
		do_up();
	else if (keycode == 83 || keycode == 40)
		do_down();
	else if (keycode == 65 || keycode == 37)
		do_left();
	else if (keycode == 68 || keycode == 39)
		do_right();
	draw_map(vars, data, map);
}
