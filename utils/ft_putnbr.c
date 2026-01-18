/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 08:33:03 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/18 14:42:35 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_recursive(n / 10);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	ret = ft_putchar((n % 10) + '0');
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_putnbr(int nbr)
{
	int				count;
	int				ret;
	unsigned int	n;

	count = 0;
	if (nbr < 0)
	{
		ret = ft_putchar('-');
		if (ret < 0)
			return (-1);
		count += ret;
		n = -(unsigned int)nbr;
	}
	else
		n = (unsigned int)nbr;
	ret = ft_putnbr_recursive(n);
	if (ret < 0)
		return (-1);
	return (count + ret);
}
