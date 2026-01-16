/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 08:33:03 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/16 08:49:16 by jkim2            ###   ########.fr       */
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
	ret = ft_print_c((n % 10) + '0');
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_putnbr(int nb)
{
	int				count;
	int				ret;
	unsigned int	n;

	count = 0;
	if (nb < 0)
	{
		ret = ft_print_c('-');
		if (ret < 0)
			return (-1);
		count += ret;
		n = -(unsigned int)nb;
	}
	else
		n = (unsigned int)nb;
	ret = ft_putnbr_recursive(n);
	if (ret < 0)
		return (-1);
	return (count + ret);
}
