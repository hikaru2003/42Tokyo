/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:09:51 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/29 20:07:42 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*char_double_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*char_single_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (NULL);
}
