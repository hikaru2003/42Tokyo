/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:49:47 by snemoto           #+#    #+#             */
/*   Updated: 2023/05/07 22:39:20 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ERROR_TOKENIZE 258
# define ERROR_PARSE 258
# define ERRPR_OPEN_REDIR 1
# define SINGLE_QUOTE_CHAR '\''
# define DOUBLE_QUOTE_CHAR '"'
# define ERROR_PREFIX "minishell: "

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <ctype.h>
# include <signal.h>
#include <libc.h>
#include <dirent.h>

extern bool						g_syntax_error;
extern int						g_last_status;
extern bool						g_readline_interrupted;
extern volatile sig_atomic_t	g_sig;

typedef struct s_token			t_token;
typedef struct s_node			t_node;

typedef enum e_token_kind
{
	TK_WORD,
	TK_RESERVED,
	TK_OP,
	TK_EOF,
}	t_token_kind;

struct s_token
{
	char			*word;
	t_token_kind	kind;
	t_token			*next;
};

typedef enum e_node_kind
{
	ND_PIPELINE,
	ND_SIMPLE_CMD,
	ND_REDIR_OUT,
	ND_REDIR_IN,
	ND_REDIR_APPEND,
	ND_REDIR_HEREDOC,
}	t_node_kind;

struct s_node
{
	t_node_kind	kind;
	t_node		*next;
	t_token		*args;
	t_node		*redirects;
	int			targetfd;
	t_token		*filename;
	t_token		*delimiter;
	bool		is_delim_unquoted;
	int			filefd;
	int			stashed_targetfd;
	int			inpipe[2];
	int			outpipe[2];
	t_node		*command;
};


extern char		**environ;
typedef struct s_list
{
	int				count;
	char			*key;
	char			*value;
	struct s_list	*next;
	struct s_list	*prev;
	int				sort_flag;
}	t_list;

//built_in_cmd.c
int		free_cmd(char **cmd);
int		built_in_cmd(char **cmd, t_list *env_head, t_node *node);

//cd.c
int		ft_cd(char **cmd, char *cwd);

//echo.c
int		ft_echo(char **cmd);

//env_to_list.c
void	insert(t_list *head, t_list *list);
void	delete(t_list *head, t_list *list);
t_list	*free_list(t_list *head);
// static t_list	*make_list(t_list *head, int i);
t_list	*env_to_list(char **environ);

//env.c
int		ft_env(t_list *env_head);

//exit.c
void	ft_exit(char **cmd);

//export1.c
int		is_append(t_list *list, t_list *env_head);
void	export_append(char **cmd, t_list *env_head, int i, int len);
int		is_new_key(t_list *env_head, t_list *new_list);
void	export_equal(char **cmd, t_list *env_head, int i, int len);
void	do_export(char **cmd, t_list *env_head, int i);

//export2.c
int		reset_flag(t_list *env_head);
int		print_export(t_list *env_head);
void	non_equal(char **cmd, t_list *env_head, int i);
int		ft_export(char **cmd, t_list *env_head);

//libft1.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);

//libft2.c
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
// static int	check_flow(long sum, char c, int flag)
int	ft_atoi(const char *str);
int	atoi_check(const char *str);

//libft3.c
void	*ft_memset(void *buf, int ch, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);

//pwd.c
int		ft_pwd(char *cwd);

//unset.c
int		ft_unset(char **cmd, t_list *env_head);

#endif

