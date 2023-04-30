/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:09:06 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/30 20:30:22 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)buf;
	while (n--)
	{
		*tmp = (unsigned char)ch;
		tmp++;
	}
	return (buf);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*rtn;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	rtn = tmp;
	while (*s1 != '\0')
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	*tmp = '\0';
	return (rtn);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	slen;
	size_t	i;

	if (s)
	{
		slen = ft_strlen(s);
		i = 0;
		while (i < slen)
		{
			write(fd, &s[i], sizeof(char));
			i++;
		}
	}
}
