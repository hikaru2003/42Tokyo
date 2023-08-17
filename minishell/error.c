/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:46:33 by snemoto           #+#    #+#             */
/*   Updated: 2023/08/03 18:32:04 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fatal_error(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s", ERROR_PREFIX);
	ft_dprintf(STDERR_FILENO, "Fatal Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	assert_error(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s", ERROR_PREFIX);
	ft_dprintf(STDERR_FILENO, "Assert Error: %s\n", msg);
	exit(255);
}

void	err_exit(const char *location, const char *msg, int status)
{
	ft_dprintf(STDERR_FILENO, "%s", ERROR_PREFIX);
	ft_dprintf(STDERR_FILENO, "%s: %s\n", location, msg);
	exit(status);
}

void	xperror(const char *location)
{
	ft_dprintf(STDERR_FILENO, "%s", ERROR_PREFIX);
	perror(location);
}

void	tokenize_error(const char *location, char **rest, char *line)
{
	g_var.g_syntax_error = true;
	ft_dprintf(STDERR_FILENO, "%s", ERROR_PREFIX);
	ft_dprintf(STDERR_FILENO, "syntax err near '%c' in %s\n", *line, location);
	while (*line)
		line++;
	*rest = line;
}
