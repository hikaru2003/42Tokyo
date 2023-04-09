/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:33:39 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/09 21:17:17 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		print_error();
	check_file(argv[1]);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		print_error();
	data->mlx = mlx_init();
	data_init(data);
	data->head = creat_map(check_file(argv[1]), data);
	if (check_map(data) != 0)
		exit(1);
	data->map = data->head.next;
	data->win = mlx_new_window(data->mlx, data->width * 32, data->height * 32, "so_long");
	draw_map(data);
	mlx_hook(data->win, 2, 1, next_frame, data);
	mlx_hook(data->win, 17, 1, ft_destroy, data);
	mlx_loop_hook(data->mlx, ft_loop, data);
	mlx_loop(data->mlx);
}

__attribute__((destructor))
static void	destructor(void){
	system("leaks -q so_long");
}
