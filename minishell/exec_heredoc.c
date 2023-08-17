/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:26:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/08/03 18:47:23 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_heredoc_line(char *line, t_list *head)
{
	char	*new_word;
	char	*p;

	p = line;
	new_word = ft_calloc(1, sizeof(char));
	if (new_word == NULL)
		fatal_error("calloc");
	while (*p)
	{
		if (is_variable(p))
			expand_variable_str(&new_word, &p, p, head);
		else if (is_special_parameter(p))
			expend_special_parameter_str(&new_word, &p, p);
		else
			append_char(&new_word, *p++);
	}
	free(line);
	return (new_word);
}

int	read_heredoc(const char *delim, bool is_delim_unquoted, t_list *head)
{
	char	*line;
	int		pfd[2];

	if (pipe(pfd) < 0)
		fatal_error("pipe");
	while (1)
	{
		line = readline("> ");
		if (line == NULL || g_var.g_rl_term || ft_strcmp(line, delim) == 0)
			break ;
		if (is_delim_unquoted)
			line = expand_heredoc_line(line, head);
		ft_dprintf(pfd[1], "%s\n", line);
		free(line);
	}
	free(line);
	close(pfd[1]);
	if (g_var.g_rl_term)
	{
		close(pfd[0]);
		return (-1);
	}
	return (pfd[0]);
}
