/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:30:43 by snemoto           #+#    #+#             */
/*   Updated: 2023/08/14 18:53:16 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*new_node(t_node_kind kind)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(*node));
	if (node == NULL)
		fatal_error("calloc");
	node->kind = kind;
	return (node);
}

bool	equal_op(t_token *tok, char *op)
{
	if (tok->kind != TK_OP)
		return (false);
	return (ft_strcmp(tok->word, op) == 0);
}

static bool	is_control_operator(t_token *tok)
{
	static char *const	operators[] = {"||", "&", "&&",
		";", ";;", "(", ")", "|", "\n"};
	size_t				i;

	i = 0;
	while (i < sizeof(operators) / sizeof(*operators))
	{
		if (check_op(tok->word, operators[i]))
			return (true);
		i++;
	}
	return (false);
}

static t_node	*new_command_node(t_token **rest, t_token *tok)
{
	t_node	*node;

	node = new_node(ND_SIMPLE_CMD);
	append_command_element(node, &tok, tok);
	while (tok && !is_eof(tok) && !is_control_operator(tok))
		append_command_element(node, &tok, tok);
	*rest = tok;
	return (node);
}

t_node	*parse(t_token **rest, t_token *tok, t_list *head)
{
	t_node	*node;

	node = new_node(ND_PIPELINE);
	node->inpipe[0] = STDIN_FILENO;
	node->inpipe[1] = -1;
	node->outpipe[0] = -1;
	node->outpipe[1] = STDOUT_FILENO;
	node->command = new_command_node(&tok, tok);
	if (equal_op(tok, "|"))
		node->next = parse(&tok, tok->next, head);
	*rest = tok;
	return (node);
}
