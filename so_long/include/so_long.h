/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:26:20 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/29 21:48:55 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

typedef struct s_map
{
	char			*row;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		height;
	int		endian;
}	t_data;

//check_file.c
int	check_file(char *file);

//check_map.c
void	insert(t_map *head, t_map *new);
t_map	creat_map(int fd, t_data *data);
int	check_map(int fd, t_data *data);

//error.c
void	write_get_file_error(char *err_msg, char *file);
void	print_error(void);

//libft
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);

//gnl
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ft_free(char **str);

//init.c
void	data_init(t_data *data);

#endif