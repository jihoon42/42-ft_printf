/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_ull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:02:00 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/18 16:02:00 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase_ull(unsigned long long nbr, char *chars, unsigned int base)
{
	int	count;
	int	ret;

	count = 0;
	if (nbr >= base)
	{
		ret = ft_putbase_ull(nbr / base, chars, base);
		if (ret < 0)
			return (-1);
		count += ret;
		ret = ft_putbase_ull(nbr % base, chars, base);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	else
	{
		ret = ft_print_c(chars[nbr]);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	return (count);
}
