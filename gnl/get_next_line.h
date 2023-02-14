/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:13:18 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/13 10:41:42 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <libc.h>

// char	*do_it(char *line, char	**save, int fd);
// void	ft_strlcat(char *line, char *buf, char *tmp);
// size_t	ft_strlen(const char *c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ft_free(char **str);

#endif