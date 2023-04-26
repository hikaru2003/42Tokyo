/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:44:41 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/26 18:14:35 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point pos, char to_fill)
{
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y || tab[pos.y][pos.x] != to_fill)
		return ;
	tab[pos.y][pos.x] = 'F';
	fill(tab, size, (t_point){pos.x + 1, pos.y}, to_fill);
	fill(tab, size, (t_point){pos.x - 1, pos.y}, to_fill);
	fill(tab, size, (t_point){pos.x, pos.y + 1}, to_fill);
	fill(tab, size, (t_point){pos.x, pos.y - 1}, to_fill);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin, tab[begin.y][begin.x]);
}