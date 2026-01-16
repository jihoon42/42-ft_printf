/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 08:19:35 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/16 13:16:06 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t nbr)
{
	char	*chars;
	int		count;
	int		ret;

	chars = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		ret = ft_putptr(nbr / 16);
		if (ret < 0)
			return (-1);
		count += ret;
		ret = ft_putptr(nbr % 16);
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
