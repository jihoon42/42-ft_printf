/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:54:40 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/18 14:42:35 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	count;
	int	ret;

	count = 0;
	if (nbr >= 10)
	{
		ret = ft_putunbr(nbr / 10);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((nbr % 10) + '0');
	if (ret < 0)
		return (-1);
	return (count + ret);
}
