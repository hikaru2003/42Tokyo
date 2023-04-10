/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:26:20 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 19:34:52 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <mlx.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h> //pid_t fork(void);
# include <sys/stat.h>
# include <fcntl.h>

# define KEY_ESC		65307

# define STDIN			0
# define STDOUT			1
# define STDERR			2

# define FRONT			0
# define UP				0
# define BACK			1
# define DOWN			1
# define RIGHT			2
# define LEFT			3

typedef struct s_map
{
	char			*row;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_map_index
{
	int	x;
	int	y;
	int	height;
	int	width;
}	t_map_index;

typedef struct s_data
{
	int		xpm_height;
	int		xpm_width;
	void	*space_img;
	void	*wall_img;
	void	*collect_img;
	void	*exit_img;
	void	*player_front_img;
	void	*player_back_img;
	void	*player_right_img;
	void	*player_left_img;
	int		player_direction;
	int		width;
	int		height;
	t_map	head;
	t_map	*map;
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		c_num;
	int		collected;
	int		exit_flag;
	int		step;
}	t_data;

//check_file.c
int		check_file(char *file);

//check_map.c
void	insert(t_map *head, t_map *new);
t_map	creat_map(int fd, t_data *data);
int		check_map(t_data *data);

//error.c
void	write_get_file_error(char *err_msg, char *file);
void	file_error(void);
void	print_error(t_data *data);

//libft
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);
int		ft_strcmp(const char *s1, const char *s2);

//printf
size_t	ft_strlen(const char *c);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	to_hexa(unsigned long long num, char *str, int *len);
void	print_conv(const char *format, va_list *args, int *len);
void	ft_putnbr_u(unsigned int n, int *len);

//gnl
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ft_free(char **str);

//init.c
void	index_init(t_map_index *index);
void	data_init(t_data *data);
void	img_init(t_data *data);

//destroy.c
int		ft_destroy(t_data *data);

//draw.c
void	draw_player(t_data *data, t_map_index *index);
void	draw_one_image(t_data *data, t_map_index *index);
int		draw_map(t_data *data);

//next_frame.c
int		next_frame(int keycode, t_data *data);
void	do_up(t_data *data);
void	do_down(t_data *data);
void	do_left(t_data *data);
void	do_right(t_data *data);

//next_frame_tool.c
void	serch_all(t_data *data);
void	move_to_player_y(t_data *data);
void	current_pos_img(t_data *data);
void	check_game_complete(t_data *data, int status);

//free.c
int		map_free(t_data *data);
int		data_free(t_data *data);

#endif
