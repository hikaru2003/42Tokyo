/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:33:39 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/05 18:10:57 by hmorisak         ###   ########.fr       */
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
	t_map	head;
	t_map	*map;
	t_vars	vars;
	t_data	img;
	int		width;
	int		height;
	int		i;
	int		j;
	int		x;
	int		y;

	if (argc != 2)
		print_error();
	check_file(argv[1]);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		print_error();
	data_init(data);
	if (check_map(check_file(argv[1]), data) != 0)
		exit(1);
	head = creat_map(check_file(argv[1]), data);
	map = head.next;
	data->width = ft_strlen(map->row) - 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->width * 32, data->height * 32, "so_long");
	img.img = mlx_xpm_file_to_image(vars.mlx, "image/dobby.xpm", &width, &height);
	i = 0;
	y = 0;
	while (i < data->height)
	{
		j = 0;
		x = 0;
		while (j < data->width)
		{
			printf("%c", map->row[j]);
			if (map->row[j] == '1')
			{
				img.img = mlx_xpm_file_to_image(vars.mlx, "image/voldemort.xpm", &width, &height);
				mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
				x += width;
			}
			else if (map->row[j] == '0')
			{
				img.img = mlx_new_image(vars.mlx, width, height);
				// img.img = mlx_xpm_file_to_image(mlx, "image/tile.xpm", &width, &height);
				mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
				x += width;
			}
			else if (map->row[j] == 'C')
			{
				img.img = mlx_xpm_file_to_image(vars.mlx, "image/dobby.xpm", &width, &height);
				mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
				x += width;
			}
			else if (map->row[j] == 'E')
			{
				img.img = mlx_xpm_file_to_image(vars.mlx, "image/dumbledore.xpm", &width, &height);
				mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
				x += width;
			}
			else
			{
				img.img = mlx_xpm_file_to_image(vars.mlx, "image/voldemort.xpm", &width, &height);
				mlx_put_image_to_window(vars.mlx, vars.win, img.img, x, y);
				x += width;
			}
			j++;
		}
		i++;
		y += height;
		map = map->next;
	}
	// mlx_loop_hook(mlx, render_next_frame, YourStruct);
	mlx_hook(vars.win, 2, 1, ft_close, &vars);
	mlx_hook(vars.win, 17, 1, ft_destroy, &vars);
	mlx_loop(vars.mlx);
}
