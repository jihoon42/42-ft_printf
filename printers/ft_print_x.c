/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:20:56 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/16 15:16:27 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int nbr, int format)
{
	char	*chars;

	if (format == 'x')
		chars = "0123456789abcdef";
	else
		chars = "0123456789ABCDEF";
	return (ft_puthex(nbr, chars));
}
