/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:00:40 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/14 19:51:20 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char		*line[FOPEN_MAX];
	char		*pt;
	static char	*save[FOPEN_MAX];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = (char *)malloc(1);
	if (!line[fd])
		return (NULL);
	line[fd] = do_it(line[fd], &save[fd], fd);
	if (!line[fd])
		return (NULL);
	if (line[fd][0] == '\0')
		return (ft_free(&line[fd]));
	if (line[fd] && ft_strchr(line[fd], '\n'))
	{
		pt = ft_strchr(line[fd], '\n') + 1;
		save[fd] = (char *)malloc(1);
		if (!save[fd])
			return (ft_free(&line[fd]));
		save[fd][0] = '\0';
		save[fd] = ft_strjoin(save[fd], pt);
		*pt = '\0';
	}
	return (line[fd]);
}
