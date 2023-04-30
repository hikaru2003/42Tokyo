/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:56:51 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/30 20:59:13 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h> 
# include <limits.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2

extern char	**environ;

//built_in_cmd.c
int		built_in_cmd(char *line);

//ft_free.c
char	*char_double_free(char **str);
char	*char_single_free(char **str);

//ft_split.c
char	*ft_strncpy(char const *s, int start, size_t len);
char	**ft_split(char const *s, char c);

//pipex.c
char	**get_path(char *cmd, char **envp);
char	*check_path(char **cmd, char **path);
void	exec(char *line, char **envp);
int		is_cmd(char *argv, char **envp);
int		all_space(char *argv);
int		pipex(char *line, char **envp);

//readline.c

//libft1.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);

//libft2.c
void	*ft_memset(void *buf, int ch, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);

#endif