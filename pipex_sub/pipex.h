/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:30:00 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/28 22:34:03 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h> //pid_t fork(void);
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h> 
//pid_t waitpid(pid_t pid, int *status_ptr, int options);

// extern char	**environ;

# define STDIN 0
# define STDOUT 1
# define STDERR 2

char	**get_path(char **envp);
char	*check_path(char **cmd, char **path);
void	exec(char *argv, char **envp);
void	pipex(char *argv, char **envp, int *pipefd, pid_t pid);
void	last_pipex(char *argv, char **envp, int *pipefd, pid_t pid);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_free(char **str);

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	to_hexa(unsigned long long num, char *str, int *len);
void	print_conv(const char *format, va_list *args, int *len);
void	ft_putnbr_u(unsigned int n, int *len);

#endif