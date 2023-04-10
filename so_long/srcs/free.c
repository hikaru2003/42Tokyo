/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:23:23 by hmorisak          #+#    #+#             */
/*   Updated: 2023/04/10 18:07:27 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_free(t_data *data)
{
	t_map	*tmp;

	tmp = data->head.next;
	data->map = data->head.next;
	while (tmp != &data->head)
	{
		tmp = data->map->next;
		free(data->map->row);
		free(data->map);
		data->map = tmp;
	}
	return (0);
}

int	data_free(t_data *data)
{
	if (!data)
		free(data);
	return (0);
}
