/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:20:16 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/18 19:54:09 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc(char **argv, char *limiter, int lmtlen)
{
	int		fd;
	int		line_len;
	char	*buf;
	char	*line;

	line = (char *)malloc(1);
	if (!line)
		return (INT_MAX);
	fd = open(".tmp.txt", (O_CREAT | O_WRONLY | O_TRUNC), 0644);
	while (1)
	{
		ft_printf("> ");
		buf = get_next_line(STDIN);
		if (!buf)
			break ;
		line_len = ft_strlen(buf);
		if ((lmtlen == line_len - 1) && !ft_strncmp(buf, limiter, lmtlen))
			break ;
		line = gnl_strjoin(line, buf);
	}
	write(fd, line, ft_strlen(line));
	gnl_free(&line);
	argv[1] = ".tmp.txt";
	return (1);
}
