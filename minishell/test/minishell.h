/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:56:51 by hmorisak          #+#    #+#             */
/*   Updated: 2023/05/01 22:58:55 by hikaru           ###   ########.fr       */
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

// #define TRUE 0
// #define FALSE -1

typedef struct s_list
{
	char			*env;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

extern char	**environ;

//built_in_cmd.c
int		unset_path(char *path, t_list *env_head);
int		built_in_cmd(char *line, t_list *env_head);

//env_to_list.c
void	insert(t_list *head, t_list *list);
void	delete(t_list *list);
t_list	*free_list(t_list *head);
t_list	*env_to_list(void);

//ft_free.c
char	*char_double_free(char **str);
char	*char_single_free(char **str);

//ft_split.c
char	*ft_strncpy(char const *s, int start, size_t len);
char	**ft_split(char const *s, char c);

//pipex.c
char	**get_path(char *cmd);
char	*check_path(char **cmd, char **path);
void	exec(char *line);
int		is_cmd(char *argv);
int		all_space(char *argv);
int		pipex(char *line);

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