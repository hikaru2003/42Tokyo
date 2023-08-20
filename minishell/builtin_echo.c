/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:24:57 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/16 19:30:05 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_option(char *cmd)
{
	int	i;

	i = 2;
	if (cmd[0] == '-' && cmd[1] == 'n')
	{
		while (cmd[i] && cmd[i] == 'n')
			i++;
		if (cmd[i] != '\0')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

int	ft_echo(char **cmd, t_node *node)
{
	int		i;
	bool	flag;

	i = 1;
	if (!cmd[i])
	{
		ft_dprintf(node->outpipe[1], "\n");
		return (0);
	}
	flag = is_option(cmd[i]);
	if (flag == TRUE)
		i = 2;
	while (cmd[i])
	{
		ft_dprintf(node->outpipe[1], "%s", cmd[i]);
		if (cmd[++i])
			ft_dprintf(node->outpipe[1], " ");
	}
	if (flag == FALSE)
		ft_dprintf(node->outpipe[1], "\n");
	return (0);
}
