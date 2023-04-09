/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:41:42 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/09 14:45:40 by hmorisak         ###   ########.fr       */
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
	if (keycode == 87 || keycode == 38)
		do_up(data);
	if (keycode == 83 || keycode == 40)
		do_down(data);
	if (keycode == 65 || keycode == 37)
		do_left(data);
	if (keycode == 68 || keycode == 39)
		do_right(data);
	draw_map(data);
	return (0);
}

void	do_up(t_data *data)
{
	int		i;
	t_map	*head;

	i = 0;
	head = data->map->prev;
	while (data->map != head)
	{
		i = 0;
		while (data->map->row[i] != '\0')
		{
			if (data->map->row[i] == 'P')
			{
				if (data->map->prev->row[i] != '1')
				{
					data->map->prev->row[i] = 'P';
					data->map->row[i] = '0';
				}
			}
			i++;
		}
		data->map = data->map->next;
	}
}

void	do_down(t_data *data)
{
	int		i;
	t_map	*head;

	i = 0;
	head = data->map->prev;
	while (data->map != head)
	{
		i = 0;
		while (data->map->row[i] != '\0')
		{
			if (data->map->row[i] == 'P')
			{
				if (data->map->next->row[i] != '1')
				{
					data->map->next->row[i] = 'P';
					data->map->row[i] = '0';
				}
			}
			i++;
		}
		data->map = data->map->next;
	}
}

void	do_left(t_data *data)
{
	int		i;
	t_map	*head;

	i = 0;
	head = data->map->prev;
	while (data->map != head)
	{
		i = 0;
		while (data->map->row[i] != '\0')
		{
			if (data->map->row[i] == 'P')
			{
				if (data->map->row[i - 1] != '1')
				{
					data->map->row[i - 1] = 'P';
					data->map->row[i] = '0';
				}
			}
			i++;
		}
		data->map = data->map->next;
	}
}

void	do_right(t_data *data)
{
	int		i;
	t_map	*head;

	i = 0;
	head = data->map->prev;
	while (data->map != head)
	{
		i = 0;
		while (data->map->row[i] != '\0')
		{
			if (data->map->row[i] == 'P')
			{
				if (data->map->row[i + 1] != '1')
				{
					data->map->row[i + 1] = 'P';
					data->map->row[i] = '0';
				}
			}
			i++;
		}
		data->map = data->map->next;
	}
}
