/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:34:24 by hmorisak          #+#    #+#             */
/*   Updated: 2023/02/28 19:43:27 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libc.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;



#endif