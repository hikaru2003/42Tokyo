/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:21:53 by hmorisak          #+#    #+#             */
/*   Updated: 2022/12/30 19:10:25 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_H
# define PF_H

# include <libc.h>

size_t	ft_strlen(const char *c);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	to_hexa(unsigned long long num, char *str, int *len);
void	print_conv(const char *format, va_list *args, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
// void	ft_print_p(va_list *args, int *len);
// void	ft_print_x(va_list *args, char conversion, int *len);
// void	ft_print_u(long long num, int *len);
// void	write_loop(const char *format, va_list *args, int *len);

#endif
