/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:46:21 by hikaru            #+#    #+#             */
/*   Updated: 2023/04/26 18:08:00 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct  s_point
{
    int	x;
    int	y;
}   t_point;

void    flood_fill(char **tab, t_point size, t_point begin);