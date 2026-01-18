/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:56:12 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/18 15:46:30 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# ifdef __linux__
#  define NULL_PTR "(nil)"
# else
#  define NULL_PTR "0x0"
# endif

int		ft_printf(const char *input_str, ...);

int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int nbr);
int		ft_putptr(unsigned long long nbr);
int		ft_puthex(unsigned int nbr, char *chars);
int		ft_putbase_ull(unsigned long long nbr, char *chars, unsigned int base);

int		ft_print_c(char c);
int		ft_print_s(char *str);
int		ft_print_d(int nbr);
int		ft_print_u(unsigned int nbr);
int		ft_print_p(unsigned long long addr);
int		ft_print_x(unsigned int nbr, int format);

#endif
