/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:49:52 by snemoto           #+#    #+#             */
/*   Updated: 2023/08/16 18:44:57 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_var;

static void	init_g_var(t_global g_var)
{
	g_var.g_sig = 0;
	g_var.g_syntax_error = false;
	g_var.g_rl_term = false;
	g_var.g_last_status = 0;
}

static t_list	*make_list(t_list *head, int i)
{
	size_t	pos;
	t_list	*list;

	pos = 0;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	while (environ[i][pos] != '=')
		pos++;
	list->key = ft_substr(environ[i], 0, pos);
	list->value = ft_substr(environ[i], pos + 1, ft_strlen(environ[i]));
	if (!list->key || !list->value)
		return (free_list(head));
	list->sort_flag = 0;
	if (ft_strcmp(list->key, "_") == 0)
		list->sort_flag = 1;
	insert(head, list);
	return (head);
}

static t_list	*env_to_list(char **environ)
{
	t_list	*head;
	int		i;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		fatal_error("malloc");
	head->count = 0;
	head->next = head;
	head->prev = head;
	i = 0;
	while (environ[i])
		if (make_list(head, i++) == NULL)
			return (NULL);
	return (head);
}

static void	handle_line(char *line, int *status, t_list *head)
{
	t_token	*tok;
	t_token	*tmp;
	t_node	*node;

	tok = tokenize(line);
	tmp = tok;
	free(line);
	if (is_eof(tok))
		;
	else if (g_var.g_syntax_error)
		*status = ERROR_TOKENIZE;
	else
	{
		node = parse(&tok, tok, head);
		if (g_var.g_syntax_error)
			*status = ERROR_PARSE;
		else
			*status = expand_and_exec(node, head);
		free_node(node);
	}
	free_tok(tmp);
}

int	main(void)
{
	char	*line;
	t_list	*head;

	setup_signal();
	init_g_var(g_var);
	head = env_to_list(environ);
	if (head == NULL)
		fatal_error("malloc");
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			break ;
		if (*line)
			add_history(line);
		g_var.g_syntax_error = false;
		handle_line(line, &g_var.g_last_status, head);
	}
	free_list(head);
	exit(g_var.g_last_status);
}
