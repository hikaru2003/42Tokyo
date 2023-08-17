/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:53:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/08/03 17:54:55 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expend_special_parameter_str(char **dst, char **rest, char *p)
{
	if (!is_special_parameter(p))
		assert_error("Expected special parameter");
	p += 2;
	append_num(dst, g_var.g_last_status);
	*rest = p;
}

void	expand_variable_str(char **dst, char **rest, char *p, t_list *head)
{
	char	*name;
	char	*value;

	name = ft_calloc(1, sizeof(char));
	if (name == NULL)
		fatal_error("calloc");
	if (*p != '$')
		assert_error("Expected dollar sign");
	p++;
	if (!is_alpha_under(*p))
		assert_error("Variable must starts with alphabet or underscore");
	append_char(&name, *p++);
	while (is_alpha_num_under(*p))
		append_char(&name, *p++);
	value = ft_getenv(head, name);
	free(name);
	if (value)
		while (*value)
			append_char(dst, *value++);
	*rest = p;
}

static void	expand_variable_tok(t_token *tok, t_list *head)
{
	char	*new_word;
	char	*p;

	if (tok == NULL || tok->kind != TK_WORD || tok->word == NULL)
		return ;
	p = tok->word;
	new_word = ft_calloc(1, sizeof(char));
	if (new_word == NULL)
		fatal_error("calloc");
	while (*p && !is_metacharacter(*p))
	{
		if (*p == SINGLE_QUOTE_CHAR)
			append_single_quote(&new_word, &p, p);
		else if (*p == DOUBLE_QUOTE_CHAR)
			append_double_quote(&new_word, &p, p, head);
		else if (is_variable(p))
			expand_variable_str(&new_word, &p, p, head);
		else if (is_special_parameter(p))
			expend_special_parameter_str(&new_word, &p, p);
		else
			append_char(&new_word, *p++);
	}
	free(tok->word);
	tok->word = new_word;
	expand_variable_tok(tok->next, head);
}

void	expand_variable(t_node *node, t_list *head)
{
	if (node == NULL)
		return ;
	expand_variable_tok(node->args, head);
	expand_variable_tok(node->filename, head);
	expand_variable(node->redirects, head);
	expand_variable(node->command, head);
	expand_variable(node->next, head);
}
