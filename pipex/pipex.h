/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:30:00 by hmorisak          #+#    #+#             */
/*   Updated: 2023/03/19 20:11:28 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <errno.h>
# include <libc.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h> //pid_t fork(void);
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h> 
# include <limits.h>
//pid_t waitpid(pid_t pid, int *status_ptr, int options);

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int		all_space(char *argv);
void	write_get_file_error(char *err_msg, char *file);
int		get_file(char *file, int status, int flag);
int		is_cmd(char *argv, char **envp);
void	pipex(int i, int argc, char *argv, char **envp);
char	**get_path(char **envp);
char	*check_path(char **cmd, char **path);
void	exec(char *argv, char **envp);
void	last_chile(char *argv, int *pipefd, char **envp);
void	do_child(char *argv, int *pipefd, char **envp);
void	do_wait(int argc);
char	*is_env(char *buf, char *limiter, char **envp);
int		here_doc(char **argv, char *limiter, int lmtlen, char **envp);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);

int		ft_printf(const char *format, ...);
void	to_hexa(unsigned long long num, char *str, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	print_conv(const char *format, va_list *args, int *len);
void	ft_putnbr_u(unsigned int n, int *len);

char	*get_next_line(int fd);
char	*gnl_strjoin(char *line, char *buf);
char	*ft_strchr(const char *s, int c);
char	*gnl_free(char **str);

char	*ft_free(char **str);

#endif