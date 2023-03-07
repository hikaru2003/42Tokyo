/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:36:53 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/07 12:00:26 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_strlcat(char *line, char *buf, char *tmp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		tmp[i] = line[i];
		i++;
	}
	while (buf[j] != '\0')
	{
		tmp[i] = buf[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

char	*ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (NULL);
}

char	*gnl_strjoin(char *line, char *buf)
{
	char	*tmp;
	size_t	len;

	if (!line || !buf)
		return (NULL);
	len = ft_strlen(line) + ft_strlen(buf);
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (NULL);
	ft_strlcat(line, buf, tmp);
	ft_free(&line);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcat(tmp, "", line);
	ft_free(&tmp);
	return (line);
}
