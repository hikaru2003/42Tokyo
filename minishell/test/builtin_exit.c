/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:27:32 by hikaru            #+#    #+#             */
/*   Updated: 2023/08/03 18:54:11 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **cmd)
{
	dprintf(STDERR_FILENO, "exit\n");
	if (cmd[1] && cmd[2])
	{
		dprintf(STDERR_FILENO, "bash: exit: too many arguments\n");
		return (1);
	}
	else if (cmd[1])
	{
		if (atoi_check(cmd[1]) == TRUE)
			exit(ft_atoi(cmd[1]));
		dprintf(2, "bash: exit: %s: numeric argument required\n", cmd[1]);
		exit(255);
	}
	exit(0);
}
