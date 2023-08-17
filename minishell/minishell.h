/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:49:47 by snemoto           #+#    #+#             */
/*   Updated: 2023/08/16 18:16:46 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ERROR_TOKENIZE 258
# define ERROR_PARSE 258
# define ERRPR_OPEN_REDIR 1
# define SINGLE_QUOTE_CHAR '\''
# define DOUBLE_QUOTE_CHAR '"'
# define ERROR_PREFIX "bash: "

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>

# include <libc.h>
# include <dirent.h>

# define CONV "cspdiuxX"
# define FLAG "#-+ 0"
# include <stdarg.h>
# include <limits.h>

typedef enum e_token_kind
{
	TK_WORD,
	TK_RESERVED,
	TK_OP,
	TK_EOF,
}	t_token_kind;

typedef enum e_node_kind
{
	ND_PIPELINE,
	ND_SIMPLE_CMD,
	ND_REDIR_OUT,
	ND_REDIR_IN,
	ND_REDIR_APPEND,
	ND_REDIR_HEREDOC,
}	t_node_kind;

typedef struct s_global
{
	volatile sig_atomic_t	g_sig;
	bool					g_syntax_error;
	bool					g_rl_term;
	int						g_last_status;
}	t_global;

extern t_global				g_var;
extern char					**environ;

typedef struct s_list
{
	int						count;
	char					*key;
	char					*value;
	struct s_list			*next;
	struct s_list			*prev;
	int						sort_flag;
}	t_list;

typedef struct s_args
{
	int						flag;
	int						spec;
	int						width;
	int						has_prec;
	int						prec;
	int						pad;
}	t_args;

typedef struct s_token		t_token;
typedef struct s_node		t_node;

struct s_token
{
	char					*word;
	t_token_kind			kind;
	t_token					*next;
};

struct s_node
{
	t_token					*args;
	t_token					*filename;
	t_token					*delim;
	t_node_kind				kind;
	t_node					*redirects;
	t_node					*command;
	t_node					*next;
	bool					is_delim_unquote;
	int						filefd;
	int						targetfd;
	int						new_targetfd;
	int						inpipe[2];
	int						outpipe[2];
};

//built_in
void	insert(t_list *head, t_list *list);
void	delete(t_list *head, t_list *list);
int		is_builtin(char **cmd);
int		built_in_cmd(char **cmd, t_list *env_head, t_node *node);

int		ft_cd(char **cmd, char *cwd, t_list *env_head);
int		ft_exit(char **cmd);
int		ft_echo(char **cmd, t_node *node);
int		ft_pwd(char *cwd, t_node *node);
int		ft_unset(char **cmd, t_list *env_head);
int		ft_env(t_list *env_head, t_node *node);

void	do_export(char **cmd, t_list *env_head, int i);
void	non_equal(char **cmd, t_list *env_head, int i, int j);
int		ft_export(char **cmd, t_list *env_head, t_node *node);

// destructor
char	**free_array(char **array);
t_list	*free_list(t_list *head);
void	free_tok(t_token *tok);
void	free_node(t_node *node);

// error
void	fatal_error(const char *msg)
		__attribute__((noreturn));
void	assert_error(const char *msg)
		__attribute__((noreturn));
void	err_exit(const char *location, const char *msg, int status)
		__attribute__((noreturn));
void	xperror(const char *location);
void	tokenize_error(const char *location, char **rest, char *line);

// exec
int		read_heredoc(const char *delim, bool is_delim_unquoted, t_list *head);

void	prepare_pipe(t_node *node);
void	prepare_pipe_child(t_node *node);
void	close_pipe(t_node *node);

int		expand_and_exec(t_node *node, t_list *head);

void	do_redirect(t_node *redir);
void	reset_redirect(t_node *redir);

int		change_fd(int fd);
int		open_redir_file(t_node *redir, t_list *head);

char	*ft_getenv(t_list *head, char *name);
char	*search_path(const char *filename, t_list *head);

char	**token_list_to_argv(t_token *tok);

// expand
void	append_char(char **s, char c);
void	append_num(char **dst, unsigned int num);
void	append_single_quote(char **dst, char **rest, char *p);
void	append_double_quote(char **dst, char **rest, char *p, t_list *head);

bool	is_alpha_under(char c);
bool	is_alpha_num_under(char c);
bool	is_variable(char *s);
bool	is_special_parameter(char *s);

void	expand_quote_removal(t_node *node);

void	expend_special_parameter_str(char **dst, char **rest, char *p);
void	expand_variable_str(char **dst, char **rest, char *p, t_list *head);
void	expand_variable(t_node *node, t_list *head);

// parse
t_token	*tokdup(t_token *tok);
void	append_command_element(t_node *command, t_token **rest, t_token *tok);

t_node	*redirect_out(t_token **rest, t_token *tok);
t_node	*redirect_in(t_token **rest, t_token *tok);
t_node	*redirect_append(t_token **rest, t_token *tok);
t_node	*redirect_heredoc(t_token **rest, t_token *tok);

bool	equal_op(t_token *tok, char *op);
t_node	*new_node(t_node_kind kind);
t_node	*parse(t_token **rest, t_token *tok, t_list *head);

// signal
void	reset_sig(int signum);
void	ignore_sig(int signum);
void	setup_sigint(void);
int		check_state(void);

void	setup_signal(void);
void	reset_signal(void);

// tokenize
bool	is_blank(char c);
bool	is_metacharacter(char c);
bool	is_word(const char *s);
bool	is_eof(t_token *tok);

t_token	*word(char **rest, char *line);

t_token	*new_token(char *word, t_token_kind kind);
bool	check_op(const char *s, const char *keyword);
t_token	*tokenize(char *line);

//libft
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *c);

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		atoi_check(const char *str);

t_list	*find_min(t_list *env_head, t_list *sort, t_list *min);
void	*ft_memset(void *buf, int ch, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

//libft-dprintf
int		ft_putchar_int(int fd, char c);
int		ft_dprintf(int fd, const char *format, ...);

int		ft_get_digits_base(unsigned int ud, int c);
int		ft_put_d(int fd, t_args *args, int d, int res);

int		ft_put_c(int fd, t_args *args, char c, int res);
int		ft_put_s(int fd, t_args *args, char *s, int res);

#endif
