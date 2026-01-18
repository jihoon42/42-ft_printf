/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkim2 <jkim2@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:08 by jkim2             #+#    #+#             */
/*   Updated: 2026/01/18 15:46:30 by jkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long long addr)
{
	int	count;
	int	ret;

	if (addr == 0)
	{
		return (ft_print_s(NULL_PTR));
	}
	count = 0;
	ret = ft_print_s("0x");
	if (ret < 0)
		return (-1);
	count += ret;
	ret = ft_putptr(addr);
	if (ret < 0)
		return (-1);
	count += ret;
	return (count);
}
