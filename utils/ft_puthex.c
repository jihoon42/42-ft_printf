/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:32:19 by jihoonkim         #+#    #+#             */
/*   Updated: 2026/01/16 08:15:13 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char *chars)
{
	int	count;
	int	ret;

	count = 0;
	if (nbr >= 16)
	{
		ret = ft_puthex(nbr / 16, chars);
		if (ret < 0)
			return (-1);
		count += ret;
		ret = ft_puthex(nbr % 16, chars);
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
