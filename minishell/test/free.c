// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   free.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/22 20:09:51 by hmorisak          #+#    #+#             */
// /*   Updated: 2023/05/03 21:30:25 by hikaru           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// char	*char_double_free(char **str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	free(str);
// 	return (NULL);
// }

// char	*char_single_free(char **str)
// {
// 	if (*str)
// 		free(*str);
// 	*str = NULL;
// 	return (NULL);
// }

// char	**free_array(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (NULL);
// }

// void	free_t_list(t_list *list_head)
// {
// 	t_list	*rm;
// 	t_list	*tmp;

// 	rm = list_head->next;
// 	while (rm != list_head)
// 	{
// 		tmp = rm->next;
// 		if (rm->env)
// 			free(rm->env);
// 		free(rm);
// 		rm = tmp;
// 	}
// 	if (list_head->env)
// 		free(list_head->env);
// 	free(list_head);
// }
