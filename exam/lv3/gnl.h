/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:56:30 by hikaru            #+#    #+#             */
/*   Updated: 2023/05/06 14:27:17 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
#define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#include <stdlib.h>
#include <unistd.h>
#include <libc.h>

char	*get_next_line(int fd);

#endif