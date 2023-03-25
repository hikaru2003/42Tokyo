/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:15:52 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/25 16:40:51 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*do_it(char *line, char	**save, int fd)
{
	ssize_t	ret;
	char	*buf;

	line[0] = '\0';
	if (*save && **save)
		line = ft_strjoin(line, *save);
	ret = 1;
	while (ret > 0 && !ft_strchr(line, '\n'))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (ft_free(&line));
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		line = ft_strjoin(line, buf);
		ft_free(&buf);
	}
	if (*save != NULL)
		ft_free(save);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*pt;
	static char	*save;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line = do_it(line, &save, fd);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
		return (ft_free(&line));
	if (line && ft_strchr(line, '\n'))
	{
		pt = ft_strchr(line, '\n') + 1;
		save = (char *)malloc(1);
		if (!save)
			return (ft_free(&line));
		save[0] = '\0';
		save = ft_strjoin(save, pt);
		*pt = '\0';
	}
	return (line);
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q a.out");
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*buf;

// 	fd = open("get_next_line.c", O_RDONLY);
// 	while (1)
// 	{
// 		buf = get_next_line(fd);
// 		printf("%s", buf);
// 		free(buf);
// 		if (!buf)
// 			break ;
// 	}
// 	close(fd);
// 	return (0);
// }
