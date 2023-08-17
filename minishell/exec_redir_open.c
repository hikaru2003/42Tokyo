/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_open.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:26:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/08/07 07:47:14 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_fd(int fd)
{
	int	newfd;

	newfd = fd + 10;
	if (dup2(fd, newfd) == -1)
		fatal_error("dup2");
	if (close(fd) < 0)
		fatal_error("close");
	return (newfd);
}

static int	check_redir_file(t_node *node, t_list *head)
{
	if (node->kind == ND_REDIR_OUT)
		node->filefd = open(node->filename->word,
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (node->kind == ND_REDIR_IN)
		node->filefd = open(node->filename->word,
				O_RDONLY);
	else if (node->kind == ND_REDIR_APPEND)
		node->filefd = open(node->filename->word,
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (node->kind == ND_REDIR_HEREDOC)
		node->filefd = read_heredoc(node->delim->word,
				node->is_delim_unquote, head);
	else
		assert_error("open_redir_file");
	return (1);
}

int	open_redir_file(t_node *node, t_list *head)
{
	if (node == NULL)
		return (0);
	if (node->kind == ND_PIPELINE)
	{
		if (open_redir_file(node->command, head) < 0)
			return (-1);
		if (open_redir_file(node->next, head) < 0)
			return (-1);
		return (0);
	}
	else if (node->kind == ND_SIMPLE_CMD)
		return (open_redir_file(node->redirects, head));
	else
		check_redir_file(node, head);
	if (node->filefd < 0)
	{
		if (node->kind == ND_REDIR_OUT
			|| node->kind == ND_REDIR_APPEND
			|| node->kind == ND_REDIR_IN)
			xperror(node->filename->word);
		return (-1);
	}
	node->filefd = change_fd(node->filefd);
	return (open_redir_file(node->next, head));
}
