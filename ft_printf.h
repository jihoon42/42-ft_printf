/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:56:12 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/16 13:23:18 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TEST
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# ifdef TEST
#  include <stdio.h>
# endif

int		ft_printf(const char *input_str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int nb);
int		ft_putptr(uintptr_t nbr);
int		ft_puthex(unsigned int nbr, char *chars);

int		ft_print_c(char c);
int		ft_print_s(char *str);
int		ft_print_d(int nbr);
int		ft_print_u(unsigned int nbr);
int		ft_print_p(uintptr_t adr);
int		ft_print_x(unsigned int nbr, int format);

#endif
