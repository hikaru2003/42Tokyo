/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:41:42 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 15:24:22 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	next_step(t_data *data)
{
	mlx_hook(data->win, 2, 1, next_frame, &data);
	return (0);
}

int	next_frame(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
		do_up(data);
	if (keycode == 1 || keycode == 125)
		do_down(data);
	if (keycode == 0 || keycode == 123)
		do_left(data);
	if (keycode == 2 || keycode == 124)
		do_right(data);
	return (0);
}

void	serch_all(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->map = data->head.next;
	while (data->map != &data->head)
	{
		x = 0;
		while (data->map->row[x] != '\0')
		{
			if (data->map->row[x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x++;
		}
		y++;
		data->map = data->map->next;
	}
}

void	do_up(t_data *data)
{
	int	y;

	y = 0;
	data->map = data->head.next;
	while (y < data->player_y)
	{
		data->map = data->map->next;
		y++;
	}
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->prev->row[data->player_x] != '1')
	{
		if (data->map->prev->row[data->player_x] == 'C')
			data->collected++;
		if (data->map->prev->row[data->player_x] == 'E' && data->collected == data->c_num)
			ft_destroy(data);
		if (data->map->prev->row[data->player_x] == 'E' && data->collected < data->c_num)
		{
			data->map->row[data->player_x] = '0';
			data->map->prev->row[data->player_x] = 'P';
			data->exit_flag = 1;
		}
		else
		{
			if (data->exit_flag == 1)
			{
				data->map->row[data->player_x] = 'E';
				data->exit_flag = 0;
			}
			else
				data->map->row[data->player_x] = '0';
			data->map->prev->row[data->player_x] = 'P';
		}
		data->player_y -= 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = BACK;
}

void	do_down(t_data *data)
{
	int	y;

	y = 0;
	data->map = data->head.next;
	while (y < data->player_y)
	{
		data->map = data->map->next;
		y++;
	}
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->next->row[data->player_x] != '1')
	{
		if (data->map->next->row[data->player_x] == 'C')
			data->collected++;
		if (data->map->next->row[data->player_x] == 'E' && data->collected == data->c_num)
			ft_destroy(data);
		if (data->map->next->row[data->player_x] == 'E' && data->collected < data->c_num)
		{
			data->map->row[data->player_x] = '0';
			data->map->next->row[data->player_x] = 'P';
			data->exit_flag = 1;
		}
		else
		{
			if (data->exit_flag == 1)
			{
				data->map->row[data->player_x] = 'E';
				data->exit_flag = 0;
			}
			else
				data->map->row[data->player_x] = '0';
			data->map->next->row[data->player_x] = 'P';
		}
		data->player_y += 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = FRONT;
}

void	do_left(t_data *data)
{
	int	y;

	y = 0;
	data->map = data->head.next;
	while (y < data->player_y)
	{
		data->map = data->map->next;
		y++;
	}
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->row[data->player_x - 1] != '1')
	{
		if (data->map->row[data->player_x - 1] == 'C')
			data->collected++;
		if (data->map->row[data->player_x - 1] == 'E' && data->collected == data->c_num)
			ft_destroy(data);
		if (data->map->row[data->player_x - 1] == 'E' && data->collected < data->c_num)
		{
			data->map->row[data->player_x] = '0';
			data->map->row[data->player_x - 1] = 'P';
			data->exit_flag = 1;
		}
		else
		{
			if (data->exit_flag == 1)
			{
				data->map->row[data->player_x] = 'E';
				data->exit_flag = 0;
			}
			else
				data->map->row[data->player_x] = '0';
			data->map->row[data->player_x - 1] = 'P';
		}
		data->player_x -= 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = LEFT;
}

void	do_right(t_data *data)
{
	int	y;

	y = 0;
	data->map = data->head.next;
	while (y < data->player_y)
	{
		data->map = data->map->next;
		y++;
	}
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (data->map->row[data->player_x + 1] != '1')
	{
		if (data->map->row[data->player_x + 1] == 'C')
			data->collected++;
		if (data->map->row[data->player_x + 1] == 'E' && data->collected == data->c_num)
			ft_destroy(data);
		if (data->map->row[data->player_x + 1] == 'E' && data->collected < data->c_num)
		{
			data->map->row[data->player_x] = '0';
			data->map->row[data->player_x + 1] = 'P';
			data->exit_flag = 1;
		}
		else
		{
			if (data->exit_flag == 1)
			{
				data->map->row[data->player_x] = 'E';
				data->exit_flag = 0;
			}
			else
				data->map->row[data->player_x] = '0';
			data->map->row[data->player_x + 1] = 'P';
		}
		data->player_x += 1;
		data->step++;
		ft_printf("steps : %d\n", data->step);
	}
	data->player_direction = RIGHT;
}
